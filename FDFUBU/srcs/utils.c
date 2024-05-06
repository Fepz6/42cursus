/*#include "../includes/fdf.h"

int get_height(char *file)
{
    char    *line;
    int fd;
    int height;

    fd = open(file, O_RDONLY, 0);
    height = 0;
    while (get_next_line(fd, &line))
    {
        height ++;
        free(line);
    }
    close(fd);
    return (height);
}

int get_width(char *file)
{
    int width;
    int fd;
    char    *line;
    char **split;

    fd = open(file, O_RDONLY, 0);
    if (get_next_line(fd, &line) <= 0) // Lê a primeira linha do arquivo
    {
        close(fd); // Fecha o arquivo
        return (0); // Retorna 0 se o arquivo estiver vazio
    }
    split = ft_strsplit(line, ' ');
    width = 0;
    while (split[width])
    {
        width++;
    }
    free(split);
    free(line);
    close(fd);
    return (width);
}

void fill_matrix(int *z_line, char *line)
{
    char **nums;
    int i = 0;

    nums = ft_strsplit(line, ' ');
    if (nums == NULL) {
        fprintf(stderr, "Failed to split line into numbers.\n");
        exit(EXIT_FAILURE);
    }

    while (nums[i])
    {
        z_line[i] = ft_atoi(nums[i]);
        free(nums[i]);
        i++;
    }
    free(nums);
}


t_dot **read_file(char *file, int width, int height)
{
    int fd;
    char *line;
    char **split;
    t_dot **matrix;
    int y;

    fd = open(file, O_RDONLY); // Abre o arquivo para leitura
    if (fd < 0) // Verifica se houve erro na abertura do arquivo
    {
        perror("Error opening file"); // Exibe uma mensagem de erro padrão
        exit(EXIT_FAILURE); // Encerra o programa com falha
    }
    
    matrix = (t_dot **)malloc(sizeof(t_dot *) * (height + 1)); // Aloca memória para a matriz de pontos
    y = 0;
    int x_offset = (1200 - width) / 3; // Calcula o deslocamento horizontal
    int y_offset = (900 - height) / 5; // Calcula o deslocamento vertical
    while (get_next_line(fd, &line) > 0) // Lê cada linha do arquivo até o final
    {   
        split = ft_strsplit(line, ' '); // Divide a linha em substrings usando o espaço como delimitador
        matrix[y] = (t_dot *)malloc(sizeof(t_dot) * (width + 1)); // Aloca memória para a linha atual da matriz
        int x = 0;
        while (split[x]) // Itera sobre as substrings para cada linha
        {
            matrix[y][x].x = x * (600 / width) + x_offset; // Calcula a coordenada x do ponto atual
            matrix[y][x].y = y * (600 / height) + y_offset; // Calcula a coordenada y do ponto atual
            matrix[y][x].z = ft_atoi(split[x]); // Converte a substring para um número inteiro e atribui à altura do ponto
            matrix[y][x].is_last = (split[x + 1] == NULL) ? 1 : 0; // Define o sinalizador de último ponto na linha       
            x++; // Incrementa o índice para acessar a próxima substring
        }
        matrix[y][x].is_last = 1; // Define o último ponto na linha
        free(line); // Libera a memória alocada para a linha
        free(split); // Libera a memória alocada para as substrings
        y++; // Incrementa o índice para acessar a próxima linha
    }
    matrix[y] = NULL; // Define o final da matriz
    close(fd); // Fecha o arquivo
    return (matrix); // Retorna a matriz de pontos preenchida com os dados do arquivo
}

int deal_close_window(void *param)
{
    // Libera os recursos alocados, como a matriz de pontos
    t_param *data = (t_param *)param;
    free_matrix(data->matrix);

    // Fecha a conexão com a interface gráfica
    mlx_destroy_window(data->mlx_ptr, data->win_ptr);
    exit(EXIT_SUCCESS); // Encerra o programa com sucesso
}*/