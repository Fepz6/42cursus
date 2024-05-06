/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcosta-e <fcosta-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 14:53:59 by felipesilva       #+#    #+#             */
/*   Updated: 2024/05/03 16:50:17 by fcosta-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include <math.h>

// Função para definir a cor de um pixel em uma imagem
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
    data->win_ptr = mlx_new_window(data->mlx_ptr, WIN_WIDTH, WIN_HEIGHT, "FDF fcosta"); // Cria uma nova janela com largura e altura definidas
    data->img_ptr = mlx_new_image(data->mlx_ptr, WIN_WIDTH, WIN_HEIGHT); // Cria uma nova imagem com largura e altura definidas
    data->img_data = (int *)mlx_get_data_addr(data->img_ptr, &(data->bits_per_pixel), &(data->size_line), &(data->endian)); // Obtém o endereço do buffer de imagem

    // Aqui podemos adicionar uma função para liberar data após o uso, se necessário.
    data->rotation_angle_x = 3.141513 / 180;
    data->rotation_angle_y = 3.141513 / 180;
}


// Função para interpolar entre duas cores
int clerp(int c1, int c2, double p)
{
    int r;
    int g;
    int b;

    if (c1 == c2) // Verifica se as cores são iguais
        return (c1); // Retorna uma das cores

    // Interpola os componentes RGB entre as duas cores com base na porcentagem p
    r = lerpi((c1 >> 16) & 0xFF, (c2 >> 16) & 0xFF, p);
    g = lerpi((c1 >> 8) & 0xFF, (c2 >> 8) & 0xFF, p);
    b = lerpi(c1 & 0xFF, c2 & 0xFF, p);

    // Retorna a cor interpolada
    return (r << 16 | g << 8 | b);
}

// Função para interpolar entre dois valores inteiros
int lerpi(int a, int b, double p)
{
    double interpolated = a + (int)((b - a) * p); // Calcula o valor interpolado entre a e b com base na porcentagem p
    return (int)(interpolated + (b - a) * p * (1.0 - p)); // Retorna o valor interpolado
}

// Função para lidar com eventos de teclado
int deal_key(int key)
{
    if (key == 65307) // Verifica se a tecla pressionada é a tecla Esc (código 53)
        exit(EXIT_SUCCESS); // Encerra o programa

    return (0); // Retorna 0 para indicar que o evento foi tratado
}



int deal_close_window(void *param)
{
    // Libera os recursos alocados, como a matriz de pontos
    t_param *data = (t_param *)param;
    free_matrix(data->matrix);

    // Fecha a conexão com a interface gráfica
    mlx_destroy_window(data->mlx_ptr, data->win_ptr);
    exit(EXIT_SUCCESS); // Encerra o programa com sucesso
}


// Função para encontrar a altura mínima e máxima na matriz de pontos
void find_min_max_height(t_dot **matrix, int *min_height, int *max_height)
{
    *min_height = matrix[0][0].z; // Inicializa a altura mínima com a primeira altura da matriz
    *max_height = matrix[0][0].z; // Inicializa a altura máxima com a primeira altura da matriz

    int y = 0;
    while (matrix[y]) // Itera sobre as linhas da matriz até encontrar uma linha nula, indicando o fim da matriz
    {
        int x = 0;
        while (!matrix[y][x].is_last) // Itera sobre os pontos da linha atual até encontrar o último ponto
        {
            if (matrix[y][x].z < *min_height) // Verifica se a altura do ponto atual é menor que a altura mínima atual
                *min_height = matrix[y][x].z; // Atualiza a altura mínima
            if (matrix[y][x].z > *max_height) // Verifica se a altura do ponto atual é maior que a altura máxima atual
                *max_height = matrix[y][x].z; // Atualiza a altura máxima
            x++; // Incrementa o índice para acessar o próximo ponto
        }
        y++; // Incrementa o índice para acessar a próxima linha
    }
}

// Função para mapear uma altura para uma cor com base em uma escala de cores
int map_height_to_color(int height, int min_height, int max_height)
{
    // Ajusta a altura mínima para 1 se for zero para evitar divisão por zero
    min_height = (min_height == 0) ? 1 : min_height;

    // Ajusta a altura para evitar valores negativos
    height = (height < min_height) ? min_height : height;

    // Calcula a porcentagem da altura em relação à altura máxima e mínima ajustadas
    double percentage = (double)(height - min_height) / (double)(max_height - min_height);

    // Define as cores mínima e máxima
    int color_min = 0xFF0000; // Vermelho
    int color_max = 0xFFFFFF; // Branco

    // Interpola as cores com base na porcentagem
    int r = lerpi((color_min >> 16) & 0xFF, (color_max >> 16) & 0xFF, percentage);
    int g = lerpi((color_min >> 8) & 0xFF, (color_max >> 8) & 0xFF, percentage);
    int b = lerpi(color_min & 0xFF, color_max & 0xFF, percentage);

    // Retorna a cor resultante
    return (r << 16 | g << 8 | b);
}

// Função para transformar coordenadas isométricas
void isometric(int *x, int *y, int *z, t_param *data)
{
    // Translada as coordenadas para a origem
    double temp_x = *x - (WIN_WIDTH / 2) - data->translate_x; // Translada a coordenada x para a origem e subtrai a translação em x
    double temp_y = *y - (WIN_HEIGHT / 2) - data->translate_y; // Translada a coordenada y para a origem e subtrai a translação em y
    double temp_z = *z; // A coordenada z não é transladada

    // Aplica as rotações
    // Rotaciona as coordenadas em torno do eixo x (inclinação para cima/baixo)
    *y = (int)(temp_y * cos(data->rotation_angle_x) - temp_z * sin(data->rotation_angle_x)); // Aplica rotação em torno do eixo x à coordenada y
    *z = (int)(temp_y * sin(data->rotation_angle_x) + temp_z * cos(data->rotation_angle_x)); // Aplica rotação em torno do eixo x à coordenada z

    // Rotaciona as coordenadas em torno do eixo y (inclinação para esquerda/direita)
    *x = (int)(temp_x * cos(data->rotation_angle_y) + *z * sin(data->rotation_angle_y)); // Aplica rotação em torno do eixo y à coordenada x
    *z = (int)(-temp_x * sin(data->rotation_angle_y) + *z * cos(data->rotation_angle_y)); // Aplica rotação em torno do eixo y à coordenada z

    // Translada as coordenadas de volta para a posição original
    *x += (WIN_WIDTH / 2) + data->translate_x; // Translada a coordenada x de volta para a posição original e adiciona a translação em x
    *y += (WIN_HEIGHT / 2) + data->translate_y; // Translada a coordenada y de volta para a posição original e adiciona a translação em y
}

// Função para desenhar uma linha entre dois pontos
void draw_line(t_param *data, t_dot a, t_dot b)
{
    // Mapeia as alturas dos pontos para cores  
    int color_a = map_height_to_color(a.z, data->min_height, data->max_height);
    int color_b = map_height_to_color(b.z, data->min_height, data->max_height);

    a.z *=  WIN_HEIGHT / (data->max_height - data->min_height ) ; // Amplifica a altura do ponto A
    b.z *= WIN_HEIGHT / (data->max_height - data->min_height) ; // Amplifica a altura do ponto B

    // Aplica a projeção isométrica aos pontos
    isometric(&(a.x), &(a.y), &(a.z), data);
    isometric(&(b.x), &(b.y), &(b.z), data);

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

// Função para desenhar os pontos na tela
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

// Função para obter a altura do arquivo
int get_height(char *file)
{
    int fd;
    char *line;
    int height;

    fd = open(file, O_RDONLY); // Abre o arquivo para leitura
    if (fd < 0) // Verifica se houve erro na abertura do arquivo
    {
        perror("Error opening file"); // Exibe uma mensagem de erro padrão
        exit(EXIT_FAILURE); // Encerra o programa com falha
    }
    height = 0;
    while (get_next_line(fd, &line) > 0) // Lê cada linha do arquivo até o final
    {
        height++; // Incrementa a contagem de linhas
        free(line); // Libera a memória alocada para a linha
    }
    close(fd); // Fecha o arquivo
   
    return (height); // Retorna o número total de linhas no arquivo
}


int get_width(char *file)
{
    int fd;
    char *line;
    char **split;
    int width;

    fd = open(file, O_RDONLY); // Abre o arquivo para leitura
    if (fd < 0) // Verifica se houve erro na abertura do arquivo
    {
        perror("Error opening file"); // Exibe uma mensagem de erro padrão
        exit(EXIT_FAILURE); // Encerra o programa com falha
    }
    if (get_next_line(fd, &line) <= 0) // Lê a primeira linha do arquivo
    {
        close(fd); // Fecha o arquivo
        return (0); // Retorna 0 se o arquivo estiver vazio
    }
    split = ft_strsplit(line, ' '); // Divide a linha em substrings usando o espaço como delimitador
    width = 0;
    while (split[width]) // Conta o número de substrings para determinar a largura
        width++;
    free(line); // Liberar memória alocada para a linha
    free(split); // Liberar memória alocada para as substrings
    close(fd); // Fecha o arquivo
    return (width); // Retorna o número total de substrings na primeira linha
}


// Função para ler o arquivo e criar a matriz de pontos
t_dot **read_file(char *file, int width, int height)
{
    float x_offset = (WIN_WIDTH - width) / 2.1f;
    float y_offset = (WIN_HEIGHT - height) / 2.6f;

    t_dot **matrix = (t_dot **)malloc(sizeof(t_dot *) * (height + 1)); 
    if (matrix == NULL) {
        perror("Error allocating memory for matrix");
        exit(EXIT_FAILURE);
    }

    int fd;
    char *line;
    char **split;
    int y;

    fd = open(file, O_RDONLY); 
    if (fd < 0) 
    {
        perror("Error opening file"); 
        exit(EXIT_FAILURE); 
    }

    y = 0;
    while (get_next_line(fd, &line) > 0) 
    {
        split = ft_strsplit(line, ' '); 
        matrix[y] = (t_dot *)malloc(sizeof(t_dot) * (width + 1)); 
        int x = 0;
        while (split[x]) 
        {
            matrix[y][x].x = x * (WIN_WIDTH - x_offset * 2) / (width - 1) + x_offset;
            matrix[y][x].y = y * (WIN_HEIGHT - y_offset * 2) / (height - 1) + y_offset;
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

// Função principal
int main(int argc, char *argv[])
{
    t_param data;
    data.matrix = NULL;

    if (argc != 2)
    {
        ft_putstr("Usage: ./fdf [map file]\n");
        return (0);
    }

    int width = get_width(argv[1]); // Obtém a largura do arquivo
    int height = get_height(argv[1]); // Obtém a altura do arquivo
    if (width == 0 || height == 0)
    {
        ft_putstr("Invalid map\n");
        return (0);
    }
    printf("Width: %d, Height: %d\n", width, height);
    data.matrix = read_file(argv[1], width, height); // Lê o arquivo e preenche a matriz de pontos
    
    data.min_height = 0; // Inicializa a altura mínima
    data.max_height = 0; // Inicializa a altura máxima
    find_min_max_height(data.matrix, &(data.min_height), &(data.max_height)); // Encontra a altura mínima e máxima na matriz de pontos
    initialize_mlx(&data); // Inicializa a interface gráfica

    draw_dots(&data); // Desenha os pontos na tela
    mlx_hook(data.win_ptr, 17, 0, deal_close_window, &data); // Registra uma função para lidar com o evento de fechar janela
    mlx_hook(data.win_ptr, 02, 1, deal_key, NULL); // Registra uma função para lidar com eventos de teclado
    mlx_loop(data.mlx_ptr); // Inicia o loop principal do MiniLibX

    free_matrix(data.matrix); // Libera a memória alocada para a matriz de pontos

    return (0); // Retorna 0 para indicar que o programa foi executado com sucesso
}
