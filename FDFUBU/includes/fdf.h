/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felipesilva <felipesilva@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 14:07:31 by felipesilva       #+#    #+#             */
/*   Updated: 2024/04/19 15:26:56 by felipesilva      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

#define WIN_WIDTH 1200
#define WIN_HEIGHT 900

# include "./libft/libft.h"
# include <math.h>
# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include "./minilibx/mlx.h"
# include "./libft/get_next_line.h"

typedef struct s_dot {
    int x;
    int y;
    int z;
    int is_last;
    	int		color;
	int		deltax;
	int		deltay; // Flag para indicar se é o último ponto na linha
} t_dot;

typedef struct t_map{
	int		width;
	int		height;
	t_dot	**dots;
	int	**z_matrix;
	int		pixel_bits;
	int		line_bytes;
	int		endian;
	int		color;
	int		pixel;
	int		error;
	int		error2;
	int		finish;
	float	x_i;
	float	y_i;
	float	center_x;
	float	center_y;

	void	*mlx;
	void	*win;
	void	*image;
	char	*image_buffer;
}	t_map;


// Estrutura para armazenar parâmetros do programa e dados de renderização
typedef struct s_param
{
    void *mlx_ptr;
    void *win_ptr;
    t_dot **matrix;
    int translate_x;
    int translate_y;
    int mouse_down;
    int map_height;
    int prev_mouse_y;
    double rotation_angle_x;
    double rotation_angle_y;
    double rotation_angle_z;
    int min_height;
    int max_height;
    void *img_ptr;
    int *img_data;
    int bits_per_pixel;
    int size_line;
    int endian;
    	int		width;
	int		height;
} t_param;



void draw_line(t_param *data, t_dot a, t_dot b);
void draw_dots(t_param *data);
int		deal_key(int key);
void rotate_dots(t_dot **matrix, float angle);
int clerp(int c1, int c2, double p);
int lerpi(int a, int b, double p);
int map_height_to_color(int height, int min_height, int max_height);
void find_min_max_height(t_dot **matrix, int *min_height, int *max_height);
void update_buffer(void *mlx_ptr, void *win_ptr, t_dot **matrix, t_param *data, void *img_ptr);
void free_matrix(t_dot **matrix);
void initialize_mlx(t_param *data);
void image_set_pixel(int *img_data, int size_line, int x, int y, int color);
t_dot **read_file(char *file, int width, int height);
void draw_point(void *mlx, void *win, t_dot point, t_param *data);
void create_image_buffer(void *mlx_ptr, t_param *data);
void draw_pixel_to_image(int x, int y, int color, t_param *data);
int deal_close_window(void *param);
void	read_map(t_map *map, int fd, char *filename);

#endif