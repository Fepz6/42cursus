/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcosta-e <fcosta-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 11:41:09 by fcosta-e          #+#    #+#             */
/*   Updated: 2023/11/04 20:28:47 by fcosta-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h" 

int main(int argc, char **argv, char **envp)
{
    t_pipex *pipex; /
    int i;
    int status;
    
    // Verifica se o número de argumentos é correto
    if (argc != 5)
        incorrect_argument();
    
    i = -1;
    // Inicializa a estrutura t_pipex com variáveis relevantes
    pipex = init_pipex(envp);
    
    // Loop para criar dois processos filhos
    while (++i < 2)
    {
        // Cria um processo filho
        pipex->pid[i] = fork();
        
        // Sai em caso de falha na criação do processo filho
        if (pipex->pid[i] < 0)
            free_exit(pipex, EXIT_FAILURE);
        
        // Se for um processo filho, executa a lógica do filho
        if (!pipex->pid[i])
            child(pipex, argv, envp, i);
    }
    
    // Fecha e espera pelos processos filhos
    close_wait(pipex, &status);
    
    // Libera recursos e sai com status de saída dos processos, se estes terminaram normalmente
    if (WIFEXITED(status))
        free_exit(pipex, WEXITSTATUS(status));
    
    // Libera recursos e sai com status, caso contrário
    free_exit(pipex, status);
}

// Encontra o caminho (PATH) no ambiente ou usa um caminho padrão se não estiver definido
char **find_path(char **envp)
{
    int i;
    char **path;
    char *temp;
    
    i = -1;
    // Percorre o ambiente em busca do PATH
    while (envp && envp[++i])
    {
        if (ft_strncmp(envp[i], "PATH=", 5) == 0)
        {
            // Separa o PATH em diferentes diretórios
            path = ft_split(envp[i] + 5, ':');
            i = -1;
            while (path[++i])
            {
                // Adiciona uma barra no final de cada diretório
                temp = path[i];
                path[i] = ft_strjoin(path[i], "/");
                free(temp);
            }
            return (path);
        }
    }
    // Se não encontrar o PATH, usa um padrão (/usr/bin/)
    path = ft_split("/usr/bin/", ' ');
    return (path);
}

// Verifica se um comando existe no caminho encontrado ou nos caminhos padrão, retorna o caminho completo para o comando
char *get_command(t_pipex *pipex, char **argument)
{
    int i;
    char *string;

    i = 0;
    // Verifica se o comando existe diretamente no diretório atual
    if (!access(argument[0], F_OK))
    {
        // Verifica se o comando é executável
        if (!access(argument[0], X_OK))
            return (argument[0]);
        else
            exit(126);
    }
    
    // Verifica nos caminhos encontrados no PATH
    while (pipex->path[i])
    {
        string = ft_strjoin(pipex->path[i], argument[0]);
        if (!access(string, F_OK))
        {
            if (!access(string, X_OK))
                return (string);
            else
                exit(126);
        }
        i++;
    }
    
    // Se não encontrar, define o erro como "No such file or directory"
    errno = ENOENT;
    return (NULL);
}

// Lógica executada por um processo filho
void child(t_pipex *pipex, char **argv, char **envp, int i)
{
    char **command;
    
    // Configuração dos pipes para redirecionamento
    piping(pipex, argv, i);
    
    // Separa os argumentos do comando
    command = ft_split(argv[i + 2], ' ');
    if (get_command(pipex, command) == NULL)
    {
        // Se não encontrar o comando, redireciona o erro para o stderr e sai com um status específico
        dup2(2, 1);
        exit(127);
    }
    
    // Executa o comando
    execve(get_command(pipex, command), command, envp);
    
    // Sai em caso de falha na execução do comando
    free_exit(pipex, EXIT_FAILURE);
}

// Configura a lógica de redirecionamento de entrada e saída dos processos filhos usando pipes
void piping(t_pipex *pipex, char **argv, int i)
{
    if (i == 0)
    {
        // Se for o primeiro processo filho, configura a entrada
        pipex->inputfd = open(argv[1], O_RDONLY);
        if (pipex->inputfd < 0)
            perror("pipex: input");
        
        // Redireciona a entrada para o arquivo ou pipe
        if (dup2(pipex->inputfd, STDIN_FILENO) < 0)
            free_exit(pipex, EXIT_FAILURE);
        
        // Fecha o descritor de arquivo da entrada
        close(pipex->inputfd);
        
        // Redireciona a saída para o próximo processo
        if (dup2(pipex->pipefd[1], STDOUT_FILENO) < 0)
            free_exit(pipex, EXIT_FAILURE);
    }
    else
    {
        // Se for o segundo processo filho, configura a saída
        pipex->outputfd = open(argv[4], O_WRONLY | O_TRUNC | O_CREAT, 0644);
        if (pipex->outputfd < 0)
            perror("pipex: output");
        
        // Redireciona a saída para o arquivo de saída ou pipe
        if (dup2(pipex->outputfd, STDOUT_FILENO) < 0)
            free_exit(pipex, EXIT_FAILURE);
        
        // Fecha o descritor de arquivo da saída
        close(pipex->outputfd);
        
        // Redireciona a entrada para receber dados do processo anterior
        if (dup2(pipex->pipefd[0], STDIN_FILENO) < 0)
            free_exit(pipex, EXIT_FAILURE);
    }
    
    // Fecha os descritores de arquivo dos pipes
    close(pipex->pipefd[0]);
    close(pipex->pipefd[1]);
}

