/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felipesilva <felipesilva@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 14:53:59 by felipesilva       #+#    #+#             */
/*   Updated: 2024/01/19 11:10:09 by felipesilva      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// main.c
#include "fdf.h"
#include <mlx.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int interpolate_color(int color_a, int color_b, double t)
{
    int red_a = (color_a >> 16) & 0xFF;
    int green_a = (color_a >> 8) & 0xFF;
    int blue_a = color_a & 0xFF;

    int red_b = (color_b >> 16) & 0xFF;
    int green_b = (color_b >> 8) & 0xFF;
    int blue_b = color_b & 0xFF;

    int interpolated_red = (int)((1 - t) * red_a + t * red_b);
    int interpolated_green = (int)((1 - t) * green_a + t * green_b);
    int interpolated_blue = (int)((1 - t) * blue_a + t * blue_b);

    return (interpolated_red << 16) | (interpolated_green << 8) | interpolated_blue;
}


int deal_key(int key, void *param)
{
    t_param *data = (t_param *)param;

    if (key == 53)
        exit(EXIT_SUCCESS);

    if (key == 126)
        data->translate_y -= 10;
    if (key == 125)
        data->translate_y += 10;
    if (key == 123)
        data->translate_x -= 10;
    if (key == 124)
        data->translate_x += 10;

    mlx_clear_window(data->mlx_ptr, data->win_ptr);
    draw_dots(data->mlx_ptr, data->win_ptr, data->matrix, data);

    return (0);
}

int deal_mouse_down(int button, int x, int y, t_param *data)
{
    if (button == 1)
    {
        // Botão esquerdo do mouse pressionado
        data->mouse_down = 1;
        data->prev_mouse_x = x;
        data->prev_mouse_y = y;
    }
    return (0);
}

int deal_mouse_up(int button, int x, int y, t_param *data)
{
	(void)y;
	(void)x;
    if (button == 1)
    {
        // Botão esquerdo do mouse liberado
        data->mouse_down = 0;
    }
    return (0);
}
int deal_mouse_move(int x, int y, t_param *data)
{
    if (data->mouse_down)
    {
        int dx = x - data->prev_mouse_x;
        int dy = y - data->prev_mouse_y;

        // Atualiza as rotações em torno dos eixos X e Y com base no movimento do mouse
        data->rotation_angle_x += dy * 0.01;
        data->rotation_angle_y += dx * 0.01;

        mlx_clear_window(data->mlx_ptr, data->win_ptr);
        draw_dots(data->mlx_ptr, data->win_ptr, data->matrix, data);

        data->prev_mouse_x = x;
        data->prev_mouse_y = y;
    }
    return (0);
}

void isometric(int *x, int *y, int *z, t_param *data)
{
    double temp_x = *x - 200 - data->translate_x;
    double temp_y = *y - 100 - data->translate_y;
    double temp_z = *z;

    // Rotação em torno do eixo X
    *y = (int)(temp_y * cos(data->rotation_angle_x) - temp_z * sin(data->rotation_angle_x));
    *z = (int)(temp_y * sin(data->rotation_angle_x) + temp_z * cos(data->rotation_angle_x));

    // Rotação em torno do eixo Y
    *x = (int)(temp_x * cos(data->rotation_angle_y) + *z * sin(data->rotation_angle_y));
    *z = (int)(-temp_x * sin(data->rotation_angle_y) + *z * cos(data->rotation_angle_y));

    // Adiciona a translação
    *x += 200 + data->translate_x;
    *y += 100 + data->translate_y;
}

void draw_line(void *mlx, void *win, t_dot a, t_dot b, t_param *data)
{
    // Fator de escala para amplificar o relevo
    double fator_escala = 25.0;

    // Amplifica a altura
    a.z *= fator_escala;
    b.z *= fator_escala;

    // Aplica a isometria
    isometric(&a.x, &a.y, &a.z, data);
    isometric(&b.x, &b.y, &b.z, data);

    int dx = abs(b.x - a.x);
    int dy = abs(b.y - a.y);
    int sx = (a.x < b.x) ? 1 : -1;
    int sy = (a.y < b.y) ? 1 : -1;
    int err = dx - dy;
    int e2;

    a.x += data->translate_x;
    a.y += data->translate_y;
    b.x += data->translate_x;
    b.y += data->translate_y;

    // Cor quando Z não se altera (azul)
    int cor_sem_alteracao = 0x0000FF;

    // Cor quando Z se altera (vermelho)
    int cor_com_alteracao = 0xFF0000;

    // Desenha a linha com as cores definidas
    while (!(a.x == b.x && a.y == b.y))
    {
        // Verifica se Z se altera
        if (a.z == b.z)
        {
            mlx_pixel_put(mlx, win, a.x, a.y, cor_sem_alteracao);
        }
        else
        {
            mlx_pixel_put(mlx, win, a.x, a.y, cor_com_alteracao);
        }

        e2 = 2 * err;
        if (e2 > -dy)
        {
            err -= dy;
            a.x += sx;
        }
        if (e2 < dx)
        {
            err += dx;
            a.y += sy;
        }
    }
}

void draw_dots(void *mlx, void *win, t_dot **matrix, t_param *data)
{
    int y;
    int x;

    y = 0;
    while (matrix[y])
    {
        x = 0;
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
                draw_line(mlx, win, matrix[y][x], matrix[y + 1][x], data);
                x++;
            }
            draw_line(mlx, win, matrix[y][x], matrix[y + 1][x], data);
        }

        y++;
    }
}



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
    int x_offset = (800 - width * 10) / 2.5;
    int y_offset = (600 - height * 10) / 2.5;
    while (get_next_line(fd, &line) > 0)
    {
        split = ft_strsplit(line, ' ');
        matrix[y] = (t_dot *)malloc(sizeof(t_dot) * (width + 1));
        int x = 0;
        while (split[x])
        {
            matrix[y][x].x = x * 30 + x_offset;
            matrix[y][x].y = y * 30 + y_offset;            matrix[y][x].z = ft_atoi(split[x]);
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

int main(int argc, char *argv[])
{
    void *mlx_ptr;
    void *win_ptr;
    t_dot **matrix;
    int width;
    int height;
    t_param data;

    if (argc != 2)
    {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return (EXIT_FAILURE);
    }

    width = get_width(argv[1]);
    height = get_height(argv[1]);
    matrix = read_file(argv[1], width, height);
    printf("Width: %d, Height: %d\n", width, height);

    mlx_ptr = mlx_init();
    win_ptr = mlx_new_window(mlx_ptr, 800, 600, "Simple FDF Viewer");

    data.mlx_ptr = mlx_ptr;
    data.win_ptr = win_ptr;
    data.matrix = matrix;
    data.translate_x = 0;
    data.translate_y = 0;
    data.mouse_down = 0;
    data.prev_mouse_x = -1;
    data.prev_mouse_y = -1;
data.rotation_angle_x = 0.0;
data.rotation_angle_y = 0.0;
data.rotation_angle_z = 0.0;


    draw_dots(mlx_ptr, win_ptr, matrix, &data);
    mlx_key_hook(win_ptr, deal_key, &data);
    mlx_mouse_hook(win_ptr, deal_mouse_down, &data);
    mlx_hook(win_ptr, 5, 0, deal_mouse_up, &data);
    mlx_hook(win_ptr, 6, 0, deal_mouse_move, &data);

    mlx_loop(mlx_ptr);

    return (EXIT_SUCCESS);
}

