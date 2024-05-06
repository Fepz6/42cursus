/*#include "../includes/fdf.h"

#define MAX(a,b) (a > b ? a : b)
#define MOD(a) ((a < 0) ? -a : a)

float   mod(float i)
{
    return (i < 0) ? -i : i;
}

void    isometric(float *x, float *y, int z)
{
    *x = (*x - *y) * cos(0.8);
    *y = (*x + *y) * sin(0.8) - z;
}

void image_set_pixel(int *img_data, int size_line, int x, int y, int color)
{
    img_data[y * (size_line / 4) + x] = color;
}

// Função para liberar a memória alocada para uma matriz de pontos
void free_matrix(t_dot **matrix)
{
    int y = 0;
    while (matrix[y]) // Itera sobre as linhas da matriz até encontrar uma linha nula, indicando o fim da matriz
    {
        free(matrix[y]); // Libera a memória alocada para a linha atual da matriz
        y++; // Incrementa o índice para acessar a próxima linha
    }
    free(matrix); // Libera a memória alocada para o ponteiro para a matriz
}

// Função para inicializar a interface gráfica usando a biblioteca MiniLibX
void initialize_mlx(t_param *data)
{
    data->mlx_ptr = mlx_init(); // Inicializa a conexão com o servidor gráfico e retorna um identificador para o objeto de conexão
    data->win_ptr = mlx_new_window(data->mlx_ptr, WIN_WIDTH, WIN_HEIGHT, "Simple FDF Viewer"); // Cria uma nova janela com largura e altura definidas
    data->img_ptr = mlx_new_image(data->mlx_ptr, WIN_WIDTH, WIN_HEIGHT); // Cria uma nova imagem com largura e altura definidas
    data->img_data = (int *)mlx_get_data_addr(data->img_ptr, &(data->bits_per_pixel), &(data->size_line), &(data->endian)); // Obtém o endereço do buffer de imagem

    data->rotation_angle_x = 0;
    data->rotation_angle_y = 0;
    // Aqui podemos adicionar uma função para liberar data após o uso, se necessário.
}

void Bresenham(int x, int y, int x1, int y1, t_map *data)
{

     printf("Bresenham: (%d, %d) -> (%d, %d)\n", x, y, x1, y1);
    // Verificando se as coordenadas estão dentro dos limites da matriz
    if (x >= 0 && y >= 0 && x < data->width && y < data->height &&
        x1 >= 0 && y1 >= 0 && x1 < data->width && y1 < data->height)
    {
        int dx = MOD(x1 - x);
        int dy = MOD(y1 - y);
        int sx = x < x1 ? 1 : -1;
        int sy = y < y1 ? 1 : -1;
        int err = (dx > dy ? dx : -dy) / 2;
        int e2;

        while (x != x1 || y != y1)
        {
            // Verificando se as coordenadas estão dentro dos limites da matriz
            if (x >= 0 && y >= 0 && x < data->width && y < data->height)
                image_set_pixel(data->img_data,data->size_line, x, y, data->color);
            e2 = err;
            if (e2 > -dx)
            {
                err -= dy;
                x += sx;
            }
            if (e2 < dy)
            {
                err += dx;
                y += sy;
            }
        }
    }
}

void draw_line(t_param *data, t_dot a, t_dot b)
{
    // Mapeia as alturas dos pontos para cores  
    int color_a = map_height_to_color(a.z, data->min_height, data->max_height);
    int color_b = map_height_to_color(b.z, data->min_height, data->max_height);

    a.z *=  WIN_HEIGHT / (data->max_height - data->min_height ) ; // Amplifica a altura do ponto A
    b.z *= WIN_HEIGHT / (data->max_height - data->min_height) ; // Amplifica a altura do ponto B

    // Aplica a projeção isométrica aos pontos
    isometric(&(a.x), &(a.y), &(a.z));
    isometric(&(b.x), &(b.y), &(b.z));

    // Calcula o número de passos para a interpolação
    int dx = abs(b.x - a.x);
    int dy = abs(b.y - a.y);
    int steps = dx > dy ? dx : dy;

    int step = 0;
    while (step <= steps) // Itera sobre os passos da interpolação
    {
        double t_pixel = (double)step / (double)steps; // Calcula a porcentagem do passo atual
        int color = clerp(color_a, color_b, t_pixel); // Interpola a cor atual

        int x = a.x + step * (b.x - a.x) / steps; // Calcula a coordenada x do pixel interpolado
        int y = a.y + step * (b.y - a.y) / steps; // Calcula a coordenada y do pixel interpolado

        // Define a cor do pixel na imagem
        image_set_pixel(data->img_data, data->size_line, x, y, color);

        step++; // Incrementa o passo
    }
}

void draw_dots(t_param *data)
{
    int y = 0;

    while (data->matrix[y] != NULL) // Itera sobre as linhas da matriz de pontos
    {
        int x = 0;

        while (data->matrix[y][x].is_last == 0) // Itera sobre os pontos da linha atual até encontrar o último ponto
        {

            // Desenha a linha com os pontos transformados
            if (!data->matrix[y][x + 1].is_last) // Verifica se não é o último ponto da linha
                draw_line(data, data->matrix[y][x], data->matrix[y][x + 1]); // Desenha uma linha entre o ponto atual e o próximo ponto na linha

            if (data->matrix[y + 1] != NULL) // Verifica se existe uma próxima linha na matriz
            {
                draw_line(data, data->matrix[y][x], data->matrix[y + 1][x]); // Desenha uma linha entre o ponto atual e o correspondente na próxima linha
            }

            x++; // Incrementa o índice para acessar o próximo ponto
        }

        y++; // Incrementa o índice para acessar a próxima linha
    }

    mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img_ptr, 0, 0); // Exibe a imagem na janela
}

void create_image(t_map *data)
{
    printf("Creating image\n"); // Verificação

    data->img_ptr = mlx_new_image(data->mlx_ptr, WIN_WIDTH, WIN_HEIGHT);
    if (data->img_ptr == NULL) {
        fprintf(stderr, "Failed to create image.\n");
        exit(EXIT_FAILURE);
    }

    printf("Image pointer: %p\n", data->img_ptr); // Verificação

    data->img_data = mlx_get_data_addr(data->img_ptr, &(data->bpp), &(data->size_line), &(data->endian));
    if (data->img_data == NULL) {
        fprintf(stderr, "Failed to get image data.\n");
        exit(EXIT_FAILURE);
    }

    printf("Image data: %p\n", data->img_data); // Verificação
}

*/