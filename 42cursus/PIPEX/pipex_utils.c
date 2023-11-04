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

#include "pipex.h"

void    free_doubleptr(char **ptr)
{
    int i;

    i = 0;
    while (ptr[i])
    {
        free(ptr[i]);
        i++;
    }
    free(ptr);
}

void    incorrect_argument(void)
{
    errno = EINVAL;
    perror(NULL);
    exit(EINVAL);
}

void    close_wait(t_pipex *pipex, int *status)
{
    close(pipex -> pipefd[0]);
    close(pipex -> pipefd[1]);
    waitpid(pipex -> pid[0], status, 0);
    waitpid(pipex -> pid[1], status, 0);
}

void    free_exit(t_pipex *pipex, int exit_status)
{
    free_doubleptr(pipex -> path);
    free(pipex -> pid);
    free(pipex);
    exit (exit_status);
}

t_pipex *init_pipex(char **envp)
{
    t_pipex *pipex;
    
    pipex = malloc(sizeof(t_pipex));
    if (!pipex)
        exit(EXIT_FAILURE);
    pipex -> pid = malloc(2 * sizeof(pid_t));
    if (!pipex -> pid)
    {
        free(pipex);
        exit(EXIT_FAILURE);
    }
    if (pipe(pipex -> pipefd) < 0)
    {
        free(pipex -> pid);
        free(pipex);
        exit(EXIT_FAILURE);
    }
    pipex -> path = find_path(envp);
    return (pipex);
}