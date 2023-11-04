/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcosta-e <fcosta-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 11:41:00 by fcosta-e          #+#    #+#             */
/*   Updated: 2023/10/27 17:01:55 by fcosta-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "./LIBFT/libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/wait.h>
# include <fcntl.h>
# include <string.h>
# include <errno.h>

typedef struct s_pipex
{
    int inputfd;
    int outputfd;
    int pipefd[2];
    pid_t   *pid;
    char    **path;
}   t_pipex;

char    **find_path(char **envp);
char    *get_command(t_pipex *pipex, char **argument);
void    child(t_pipex *pipex, char **argv, char **envp, int i);
void    piping(t_pipex *pipex, char **argv, int i);

void    free_doubleptr(char **ptr);
void    incorrect_argument(void);
void    close_wait(t_pipex *pipex, int *status);
void    free_exit(t_pipex *pipex, int exit_st);
t_pipex *init_pipex(char **envp);

#endif