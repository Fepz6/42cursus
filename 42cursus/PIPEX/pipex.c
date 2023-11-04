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
    t_pipex *pipex;
    int i;
    int status;
    
    if (argc != 5)
        incorrect_argument();
    i = -1;
    pipex = init_pipex(envp);
    while (++i < 2)
    {
        pipex -> pid[i] = fork();
        if (pipex -> pid[i] < 0)
            free_exit(pipex, EXIT_FAILURE);
        if (!pipex -> pid[i])
            child(pipex, argv, envp, i);
    }
    close_wait(pipex, &status);
    if (WIFEXITED(status))
        free_exit(pipex, WEXITSTATUS(status));
    free_exit(pipex, status);
}

char **find_path(char **envp)
{
    int i;
    char    **path;
    char    *temp;
    
    i = -1;
    while (envp && envp[++i])
    {
        if (ft_strncmp(envp[i], "PATH=", 5) == 0)
        {
            path = ft_split(envp[i] + 5, ':');
            i = -1;
            while (path[++i])
            {
                temp = path[i];
                path[i] = ft_strjoin(path[i], "/");
                free(temp);
            }
            return (path);
        }
    }
    path = ft_split("/usr/bin/", ' ');
    return (path);
}

char    *get_command(t_pipex *pipex, char **argument)
{
    int i;
    char    *string;

    i = 0;
    if (!access(argument[0], F_OK))
    {
        if (!access(argument[0], X_OK))
            return (argument[0]);
        else
            exit(126);
    }
    while (pipex -> path[i])
    {
        string = ft_strjoin(pipex -> path[i], argument[0]);
        if (!access(string, F_OK))
        {
            if (!access(string, X_OK))
                return (string);
            else
                exit(126);
        }
        i++;
    }
    errno = ENOENT;
    return (NULL);
}

void    child(t_pipex *pipex, char **argv, char **envp, int i)
{
    char    **command;
    
    piping(pipex, argv, i);
    command = ft_split(argv[i + 2], ' ');
    if (get_command(pipex, command) == NULL)
    {
        dup2(2,1);
        //printf
        exit(127);
    }
    execve(get_command(pipex, command), command, envp);
    free_exit(pipex, EXIT_FAILURE);
}

void    piping(t_pipex *pipex, char **argv, int i)
{
    if (i ==0)
    {
        pipex -> inputfd = open(argv[1], O_RDONLY);
        if (pipex -> inputfd < 0)
            perror("pipex: input");
        if (dup2(pipex -> inputfd, STDIN_FILENO) < 0)
            free_exit(pipex, EXIT_FAILURE);
        close(pipex -> inputfd);
        if (dup2(pipex -> pipefd[1], STDOUT_FILENO) < 0)
            free_exit(pipex, EXIT_FAILURE);
    }
    else
    {
        pipex -> outputfd = open(argv[4], O_WRONLY | O_TRUNC | O_CREAT, 0644);
        if (pipex -> outputfd < 0)
            perror("pipex: output");
        if (dup2(pipex -> outputfd, STDOUT_FILENO) < 0)
            free_exit(pipex, EXIT_FAILURE);
        close (pipex -> outputfd);
        if (dup2(pipex -> pipefd[0], STDIN_FILENO) < 0)
            free_exit(pipex, EXIT_FAILURE);  
    }
    close(pipex -> pipefd[0]);
    close(pipex -> pipefd[1]);
}