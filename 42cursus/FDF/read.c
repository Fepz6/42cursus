/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felipesilva <felipesilva@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 13:11:40 by felipesilva       #+#    #+#             */
/*   Updated: 2023/12/24 01:00:00 by felipesilva      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


/*
#include "fdf.h"
 // Certifique-se de incluir o cabeçalho para a função get_next_line
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>

// Restante do seu código...

void read_file(char *filename)
{
    int fd = open(filename, O_RDONLY);
    if (fd < 0)
    {
        perror("Erro ao abrir o arquivo");
        exit(EXIT_FAILURE);
    }

    char *line = NULL;

    while (get_next_line(fd, &line) > 0)
    {
        // Imprimir a linha lida
        printf("%s\n", line);

        // Libere a memória alocada pela get_next_line
        free(line);
        line = NULL;
    }

    if (line != NULL)
        free(line);

    close(fd);
}

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        fprintf(stderr, "Uso: %s <nome_do_arquivo>\n", argv[0]);
        return EXIT_FAILURE;
    }

    read_file(argv[1]);

    return EXIT_SUCCESS;
}



#include "fdf.h"
#include <mlx.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>


void draw_line(void *mlx, void *win, int x0, int y0, int x1, int y1, int color)
{
    int dx = abs(x1 - x0);
    int dy = abs(y1 - y0);
    int sx = (x0 < x1) ? 1 : -1;
    int sy = (y0 < y1) ? 1 : -1;
    int err = dx - dy;
    int e2;

    while (!(x0 == x1 && y0 == y1))
    {
        mlx_pixel_put(mlx, win, x0, y0, color);
        e2 = 2 * err;
        if (e2 > -dy)
        {
            err -= dy;
            x0 += sx;
        }
        if (e2 < dx)
        {
            err += dx;
            y0 += sy;
        }
    }
}

void read_file(char *filename, void *mlx, void *win)
{
    int fd = open(filename, O_RDONLY);
    if (fd < 0)
    {
        perror("Erro ao abrir o arquivo");
        exit(EXIT_FAILURE);
    }

    char *line = NULL;
    Point last_point = {0, 0, 0};
    Point current_point;

    while (get_next_line(fd, &line) > 0)
    {
        char **coords = ft_strsplit(line, ' ');

        for (int i = 0; coords[i] != NULL; i++)
        {
            current_point.x = i * 10 + 400; // Ajuste de escala
            current_point.y = ft_atoi(coords[i]) * 10 + 300; // Ajuste de escala
            current_point.z = i * 10;

            // Desenha uma linha entre o ponto atual e o ponto anterior
            draw_line(mlx, win, last_point.x, last_point.y, current_point.x, current_point.y, 0xFFFFFF);

            last_point = current_point;
        }

        free(line);
        free(coords);
    }

    close(fd);
}

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        fprintf(stderr, "Uso: %s <nome_do_arquivo>\n", argv[0]);
        return EXIT_FAILURE;
    }

    void *mlx = mlx_init();
    void *win = mlx_new_window(mlx, 800, 600, "Simple FDF Viewer");

    printf("Iniciando leitura do arquivo...\n");
    read_file(argv[1], mlx, win);
    printf("Leitura do arquivo concluída.\n");

    mlx_loop(mlx);

    return EXIT_SUCCESS;
}

*/