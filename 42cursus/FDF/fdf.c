/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felipesilva <felipesilva@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 14:53:59 by felipesilva       #+#    #+#             */
/*   Updated: 2024/04/11 17:23:10 by felipesilva      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <mlx.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

void image_set_pixel(void *mlx, void *win, int x, int y, int color)
{
    mlx_pixel_put(mlx, win, x, y, color);
}


void free_matrix(t_dot **matrix)
{
    int y = 0;
    while (matrix[y])
    {
        free(matrix[y]);
        y++;
    }
    free(matrix);
}

void initialize_mlx(t_param *data)
{
    data->mlx_ptr = mlx_init();
    data->win_ptr = mlx_new_window(data->mlx_ptr, WIN_WIDTH, WIN_HEIGHT, "Simple FDF Viewer");
}

// Comentário: Definição da função clerp para realizar interpolação de cor linear
int clerp(int c1, int c2, double p)
{
    int r;
    int g;
    int b;

    // Comentário: Se as cores forem iguais, retorna uma das cores
    if (c1 == c2)
        return (c1);

    // Comentário: Interpolação linear separada para cada componente RGB
    r = lerpi((c1 >> 16) & 0xFF, (c2 >> 16) & 0xFF, p);
    g = lerpi((c1 >> 8) & 0xFF, (c2 >> 8) & 0xFF, p);
    b = lerpi(c1 & 0xFF, c2 & 0xFF, p);

    // Comentário: Combina os componentes interpolados para formar a cor final
    return (r << 16 | g << 8 | b);
}

// Comentário: Definição da função lerpi para realizar interpolação linear
int lerpi(int a, int b, double p)
{
    // Comentário: Ajusta a interpolação para enfatizar as mudanças
    double interpolated = a + (int)((b - a) * p);
    return (int)(interpolated + (b - a) * p * (1.0 - p));
}

// Comentário: Função para lidar com eventos de teclado
int deal_key(int key)
{
    // Comentário: Se a tecla pressionada for a tecla Esc (53 no macOS), encerra o programa
    if (key == 53)
        exit(EXIT_SUCCESS);

    return (0);
}

// Comentário: Função chamada quando o botão do mouse é pressionado
int deal_mouse_down(int button, int x, int y, t_param *data)
{
    if (button == 1)
    {
        // Comentário: Botão esquerdo do mouse pressionado
        data->mouse_down = 1;
        data->prev_mouse_x = x;
        data->prev_mouse_y = y;
    }
    return (0);
}

// Comentário: Função chamada quando o botão do mouse é liberado
int deal_mouse_up(int button, int x, int y, t_param *data)
{
    (void)y;
    (void)x;
    if (button == 1)
    {
        // Comentário: Botão esquerdo do mouse liberado
        data->mouse_down = 0;
    }
    return (0);
}

// Comentário: Função chamada quando o mouse é movido
int deal_mouse_move(int x, int y, t_param *data)
{
    if (data->mouse_down)
    {
        int dx = x - data->prev_mouse_x;
        int dy = y - data->prev_mouse_y;

        // Comentário: Atualiza as rotações em torno dos eixos X e Y com base no movimento do mouse
        data->rotation_angle_x += dy * 0.005;
        data->rotation_angle_y += dx * 0.005;

        mlx_clear_window(data->mlx_ptr, data->win_ptr);
        draw_dots(data->mlx_ptr, data->win_ptr, data->matrix, data);

        data->prev_mouse_x = x;
        data->prev_mouse_y = y;
    }
    return (0);
}

// Comentário: Função para encontrar as alturas mínima e máxima na matriz de pontos
void find_min_max_height(t_dot **matrix, int *min_height, int *max_height)
{
    *min_height = matrix[0][0].z;
    *max_height = matrix[0][0].z;

    int y = 0;
    while (matrix[y])
    {
        int x = 0;
        while (!matrix[y][x].is_last)
        {
            if (matrix[y][x].z < *min_height)
                *min_height = matrix[y][x].z;
            if (matrix[y][x].z > *max_height)
                *max_height = matrix[y][x].z;
            x++;
        }
        y++;
    }
}

// Comentário: Função para mapear a altura para uma cor
int map_height_to_color(int height, int min_height, int max_height)
{
    // Comentário: Ajusta a altura para garantir que esteja dentro dos limites
    height = (height < min_height) ? min_height : height;
    height = (height > max_height) ? max_height : height;

    // Comentário: Define as cores para altura mínima e máxima
    int color_min = 0xFF0000; // Vermelho
    int color_max = 0xFFFFFF; // Branco

    // Comentário: Calcula a porcentagem ajustada entre a altura mínima e máxima
    double percentage = (double)(height - min_height) / (double)(max_height - min_height);

    // Comentário: Interpolação linear entre as cores
    int r = lerpi((color_min >> 16) & 0xFF, (color_max >> 16) & 0xFF, percentage);
    int g = lerpi((color_min >> 8) & 0xFF, (color_max >> 8) & 0xFF, percentage);
    int b = lerpi(color_min & 0xFF, color_max & 0xFF, percentage);

    return (r << 16 | g << 8 | b);
}

// Função para otimizar a transformação isométrica
void isometric(int *x, int *y, int *z, t_param *data)
{
    double temp_x = *x - (WIN_WIDTH / 2) - data->translate_x;
    double temp_y = *y - (WIN_HEIGHT / 2) - data->translate_y;
    double temp_z = *z;

    // Rotação em torno do eixo X
    *y = (int)(temp_y * cos(data->rotation_angle_x) - temp_z * sin(data->rotation_angle_x));
    *z = (int)(temp_y * sin(data->rotation_angle_x) + temp_z * cos(data->rotation_angle_x));

    // Rotação em torno do eixo Y
    *x = (int)(temp_x * cos(data->rotation_angle_y) + *z * sin(data->rotation_angle_y));
    *z = (int)(-temp_x * sin(data->rotation_angle_y) + *z * cos(data->rotation_angle_y));

    // Adiciona a translação
    *x += (WIN_WIDTH / 2) + data->translate_x;
    *y += (WIN_HEIGHT / 2) + data->translate_y;
}

// Comentário: Função para desenhar uma linha entre dois pontos
void draw_line(void *mlx, void *win, t_dot a, t_dot b, t_param *data)
{
    int color_a = map_height_to_color(a.z, data->min_height, data->max_height);
    int color_b = map_height_to_color(b.z, data->min_height, data->max_height);

    a.z *= 5.0;
    b.z *= 5.0;

    isometric(&a.x, &a.y, &a.z, data);
    isometric(&b.x, &b.y, &b.z, data);

    // Limita as coordenadas ao intervalo da janela
    a.x = fmin(fmax(a.x, 0), WIN_WIDTH - 1);
    a.y = fmin(fmax(a.y, 0), WIN_HEIGHT - 1);
    b.x = fmin(fmax(b.x, 0), WIN_WIDTH - 1);
    b.y = fmin(fmax(b.y, 0), WIN_HEIGHT - 1);

    int dx = abs(b.x - a.x);
    int dy = abs(b.y - a.y);
    int steps = dx > dy ? dx : dy;

    int step = 0;
    while (step <= steps)
    {
        double t_pixel = (double)step / (double)steps;
        int color = clerp(color_a, color_b, t_pixel);

        int x = a.x + step * (b.x - a.x) / steps;
        int y = a.y + step * (b.y - a.y) / steps;

        image_set_pixel(mlx, win, x, y, color);

        step++;
    }
}

// Comentário: Função para desenhar todos os pontos na matriz
void draw_dots(void *mlx, void *win, t_dot **matrix, t_param *data)
{
    int y = 0;

    while (matrix[y] != NULL)
    {
        int x = 0;

        while (matrix[y][x].is_last == 0)
        {
            draw_line(mlx, win, matrix[y][x], matrix[y][x + 1], data);
            x++;
        }

        if (matrix[y + 1] != NULL)
        {
            x = 0;

            while (matrix[y + 1][x].is_last == 0)
            {
                draw_line(mlx, win, matrix[y][x], matrix[y + 1][x], data);
                x++;
            }

            draw_line(mlx, win, matrix[y][x], matrix[y + 1][x], data);
        }

        y++;
    }
}

// Comentário: Função para obter a altura total do arquivo
int get_height(char *file)
{
    int fd;
    char *line;
    int height;

    fd = open(file, O_RDONLY);
    if (fd < 0)
    {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }
    height = 0;
    while (get_next_line(fd, &line) > 0)
    {
        height++;
        free(line);
    }
    close(fd);
    return (height);
}

// Comentário: Função para obter a largura total do arquivo
int get_width(char *file)
{
    int fd;
    char *line;
    char **split;
    int width;

    fd = open(file, O_RDONLY);
    if (fd < 0)
    {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }
    if (get_next_line(fd, &line) <= 0)
    {
        close(fd);
        return (0);
    }
    split = ft_strsplit(line, ' ');
    width = 0;
    while (split[width])
        width++;
    close(fd);
    return (width);
}

// Comentário: Função para ler o arquivo e preencher a matriz de pontos
t_dot **read_file(char *file, int width, int height)
{
    int fd;
    char *line;
    char **split;
    t_dot **matrix;
    int y;

    fd = open(file, O_RDONLY);
    if (fd < 0)
    {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }
    matrix = (t_dot **)malloc(sizeof(t_dot *) * (height + 1));
    y = 0;
    int x_offset = (1200 - width) / 2;
    int y_offset = (900 - height) / 4.5;
    while (get_next_line(fd, &line) > 0)
    {   
        split = ft_strsplit(line, ' ');
        matrix[y] = (t_dot *)malloc(sizeof(t_dot) * (width + 1));
        int x = 0;
        while (split[x])
        {
            matrix[y][x].x = x * 2 + x_offset;
            matrix[y][x].y = y * 2 + y_offset;
            matrix[y][x].z = ft_atoi(split[x]);
            matrix[y][x].is_last = (split[x + 1] == NULL) ? 1 : 0;
            x++;
        }
        matrix[y][x].is_last = 1;
        free(line);
        free(split);
        y++;
    }
    matrix[y] = NULL;
    close(fd);
    return (matrix);
}

// Comentário: Função principal
int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return (EXIT_FAILURE);
    }

    int width = get_width(argv[1]);
    int height = get_height(argv[1]);
    t_dot **matrix = read_file(argv[1], width, height);

    printf("Width: %d, Height: %d\n", width, height);

    int min_height, max_height;
    find_min_max_height(matrix, &min_height, &max_height);
    printf("Min Height: %d, Max Height: %d\n", min_height, max_height);

    t_param data;

    initialize_mlx(&data);

    data.matrix = matrix;
    data.translate_x = 0;
    data.translate_y = 0;
    data.mouse_down = 0;
    data.prev_mouse_x = -1;
    data.prev_mouse_y = -1;
    data.rotation_angle_x = 0.0;
    data.rotation_angle_y = 0.0;
    data.rotation_angle_z = 0.0;
    data.min_height = min_height;
    data.max_height = max_height;

    draw_dots(data.mlx_ptr, data.win_ptr, matrix, &data);
    mlx_key_hook(data.win_ptr, deal_key, &data);
    mlx_mouse_hook(data.win_ptr, deal_mouse_down, &data);
    mlx_hook(data.win_ptr, 5, 0, deal_mouse_up, &data);
    mlx_hook(data.win_ptr, 6, 0, deal_mouse_move, &data);

    mlx_loop(data.mlx_ptr);

    free_matrix(matrix);

    return (EXIT_SUCCESS);
}