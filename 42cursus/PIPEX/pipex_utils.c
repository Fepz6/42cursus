/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcosta-e <fcosta-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 17:19:19 by fcosta-e          #+#    #+#             */
/*   Updated: 2023/11/03 17:34:08 by fcosta-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Libera a memória alocada para um array de strings e para o próprio array
void free_doubleptr(char **ptr)
{
    int i;

    i = 0;
    while (ptr[i])
    {
        free(ptr[i]); // Libera cada string dentro do array
        i++;
    }
    free(ptr); // Libera o array de strings
}

// Reporta um erro de argumento incorreto e termina o programa
void incorrect_argument(void)
{
    errno = EINVAL; // Define o código de erro como "Invalid argument"
    perror(NULL); // Exibe a mensagem de erro correspondente a EINVAL
    exit(EINVAL); // Sai do programa com o código de erro EINVAL
}

// Fecha os pipes e espera pelos processos filhos
void close_wait(t_pipex *pipex, int *status)
{
    close(pipex->pipefd[0]); // Fecha o lado de leitura do pipe
    close(pipex->pipefd[1]); // Fecha o lado de escrita do pipe
    waitpid(pipex->pid[0], status, 0); // Espera pelo primeiro processo filho
    waitpid(pipex->pid[1], status, 0); // Espera pelo segundo processo filho
}

// Libera a memória alocada para a estrutura t_pipex e termina o programa com um status de saída
void free_exit(t_pipex *pipex, int exit_status)
{
    free_doubleptr(pipex->path); // Libera a memória alocada para o PATH
    free(pipex->pid); // Libera a memória alocada para os PIDs dos processos filhos
    free(pipex); // Libera a memória alocada para a estrutura t_pipex
    exit(exit_status); // Sai do programa com o status de saída fornecido
}

// Inicializa a estrutura t_pipex alocando memória e configurando os pipes
t_pipex *init_pipex(char **envp)
{
    t_pipex *pipex;
    
    // Aloca memória para a estrutura t_pipex
    pipex = malloc(sizeof(t_pipex));
    if (!pipex)
        exit(EXIT_FAILURE); // Sai se a alocação de memória falhar
    
    // Aloca memória para os PIDs dos processos filhos
    pipex->pid = malloc(2 * sizeof(pid_t));
    if (!pipex->pid)
    {
        free(pipex); // Libera a memória alocada para t_pipex se a alocação falhar
        exit(EXIT_FAILURE); // Sai se a alocação de memória falhar
    }
    
    // Cria um pipe para comunicação entre os processos
    if (pipe(pipex->pipefd) < 0)
    {
        free(pipex->pid); // Libera a memória alocada para os PIDs se a criação do pipe falhar
        free(pipex); // Libera a memória alocada para t_pipex se a criação do pipe falhar
        exit(EXIT_FAILURE); // Sai se a criação do pipe falhar
    }
    
    // Obtém o caminho PATH do ambiente
    pipex->path = find_path(envp);
    
    return (pipex); // Retorna a estrutura t_pipex inicializada
}

