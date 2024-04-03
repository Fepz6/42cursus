/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felipesilva <felipesilva@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 14:07:31 by felipesilva       #+#    #+#             */
/*   Updated: 2024/03/15 14:40:52 by felipesilva      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

#define WIN_WIDTH 1200
#define WIN_HEIGHT 900

# include "./LIBFT/libft.h"
# include <math.h>
# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include "./minilibx_macos/mlx.h"
# include "./LIBFT/get_next_line.h"

# define PRM matrix[0][0]

typedef struct s_vector
{
    int x;
    int y;
} t_vector;

typedef struct s_lin
{
    t_vector start;
    t_vector stop;
    int dx;
    int sx;
    int dy;
    int sy;
    int err;
    int err2;
} t_lin;

typedef struct s_point
{
    int x;
    int y;
    int z;
} t_point;

typedef struct
{
    int x;
    int y;
    int z;
} Point;

typedef struct	s_mouse
{
	int			isdown;
	int			x;
	int			y;
	int			lastx;
	int			lasty;
	int prev_x;
	int prev_y;
}				t_mouse;

typedef struct s_dot {
    int x;
    int y;
    int z;
    int is_last; // Flag para indicar se é o último ponto na linha
} t_dot;

// Estrutura para armazenar parâmetros do programa e dados de renderização
typedef struct s_param {
    void *mlx_ptr; // Ponteiro para a instância do MiniLibX
    void *win_ptr; // Ponteiro para a janela do MiniLibX
    t_dot **matrix; // Matriz de pontos do mapa
    int translate_x; // Translação em X
    int translate_y; // Translação em Y
    int mouse_down; // Flag indicando se o botão do mouse está pressionado
    int prev_mouse_x; // Posição anterior do mouse (X)
    int prev_mouse_y; // Posição anterior do mouse (Y)
    double rotation_angle_x; // Ângulo de rotação em torno do eixo X
    double rotation_angle_y; // Ângulo de rotação em torno do eixo Y
    double rotation_angle_z; // Ângulo de rotação em torno do eixo Z
    int min_height; // Altura mínima do mapa
    int max_height; // Altura máxima do mapa
} t_param;





void draw_line(void *mlx, void *win, t_dot a, t_dot b, t_param *data);
void draw_dots(void *mlx, void *win, t_dot **matrix, t_param *data);
int		deal_key(int key);
void rotate_dots(t_dot **matrix, float angle);
int clerp(int c1, int c2, double p);
int lerpi(int a, int b, double p);
int map_height_to_color(int height, int min_height, int max_height);
void find_min_max_height(t_dot **matrix, int *min_height, int *max_height);
void update_buffer(void *mlx_ptr, void *win_ptr, t_dot **matrix, t_param *data, void *img_ptr);
void free_matrix(t_dot **matrix);
void initialize_mlx(t_param *data);
void image_set_pixel(void *mlx, void *win, int x, int y, int color);
t_dot **read_file(char *file, int width, int height);
void draw_point(void *mlx, void *win, t_dot point, t_param *data);




#endif