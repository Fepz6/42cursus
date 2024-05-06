#include "../includes/fdf.h"
#include <math.h>


/*
int main(int argc, char **argv)
{
    t_map *data;

    data = (t_map*)malloc(sizeof(t_map));
    read_file(argv[1], data);
    if (argc != 2)
    {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return 1;
    }
    data->mlx_ptr = mlx_init();
    data->win_ptr = mlx_new_window(data->mlx_ptr, 1000, 1000, "FDF");
    data->zoom = 20;
    create_image
    draw_line(data);

    mlx_loop(data->mlx_ptr);


}*/