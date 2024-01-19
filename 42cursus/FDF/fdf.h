/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felipesilva <felipesilva@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 14:07:31 by felipesilva       #+#    #+#             */
/*   Updated: 2024/01/07 01:01:26 by felipesilva      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H



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

typedef struct	s_dot
{
	int			x;
	int			y;
	int			z;
	int			is_last;
}				t_dot;

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

// Adicione os seguintes campos à sua estrutura t_param
typedef struct s_param
{
    void *mlx_ptr;
    void *win_ptr;
    t_dot **matrix;
    int translate_x;
    int translate_y;
    int mouse_down;
    int prev_mouse_x;
    int prev_mouse_y;
    double rotation_angle_x;
    double rotation_angle_y;
    double rotation_angle_z;
    int min_height;  // Novo
    int max_height;  // Novo
} t_param;



void draw_line(void *mlx, void *win, t_dot a, t_dot b, t_param *data);
void draw_dots(void *mlx, void *win, t_dot **matrix, t_param *data);
int		deal_key(int key, void *param);
void rotate_dots(t_dot **matrix, float angle);
int clerp(int c1, int c2, double p);


#endif