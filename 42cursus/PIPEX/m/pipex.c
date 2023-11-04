/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcosta-e <fcosta-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 11:41:09 by fcosta-e          #+#    #+#             */
/*   Updated: 2023/10/05 12:30:52 by fcosta-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>

int main(int argc, char *argv[]) {
    if (argc != 5) {
        fprintf(stderr, "Uso: %s arquivo1 comando1 comando2 arquivo2\n", argv[0]);
        return 1;
    }

    char *file1 = argv[1];
    char *cmd1 = argv[2];
    char *cmd2 = argv[3];
    char *file2 = argv[4];

    int pipe_fd[2];
    pid_t child1, child2;

    if (pipe(pipe_fd) == -1) {
        perror("pipe");
        return 2;
    }

    child1 = fork();
    if (child1 == -1) {
        perror("fork");
        return 3;
    }

    if (child1 == 0) {
        // Child 1 code
        close(pipe_fd[0]); // Close read end of the pipe
        dup2(pipe_fd[1], STDOUT_FILENO); // Redirect stdout to the pipe

        int fd = open(file1, O_RDONLY);
        if (fd == -1) {
            perror("open");
            exit(4);
        }

        dup2(fd, STDIN_FILENO); // Redirect stdin to file1

        execlp(cmd1, cmd1, NULL);
        perror("execlp");
        exit(5);
    } else {
        child2 = fork();
        if (child2 == -1) {
            perror("fork");
            return 6;
        }

        if (child2 == 0) {
            // Child 2 code
            close(pipe_fd[1]); // Close write end of the pipe
            dup2(pipe_fd[0], STDIN_FILENO); // Redirect stdin to the pipe

            int fd = open(file2, O_WRONLY | O_CREAT | O_TRUNC, 0644);
            if (fd == -1) {
                perror("open");
                exit(7);
            }

            dup2(fd, STDOUT_FILENO); // Redirect stdout to file2

            execlp(cmd2, cmd2, NULL);
            perror("execlp");
            exit(8);
        } else {
            // Parent code
            close(pipe_fd[0]);
            close(pipe_fd[1]);

            waitpid(child1, NULL, 0);
            waitpid(child2, NULL, 0);
        }
    }

    return 0;
}
