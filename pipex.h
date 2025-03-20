/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acosi <acosi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 11:02:17 by acosi             #+#    #+#             */
/*   Updated: 2025/03/20 19:25:49 by acosi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <stdlib.h>
# include <sys/types.h>
# include <fcntl.h>
# include <stdio.h>
# include <errno.h>
# include <sys/wait.h>
# include "libft/libft.h"

# define READ 0
# define WRITE 1
# define OUTPUT 0
# define INPUT 1
# define STDOUT 0
# define STDIN 1
# define CHILD 0

# define RED "\033[31m"
# define GREEN "\033[32m"
# define YELLOW "\033[33m"
# define BLUE "\033[34m"
# define MAGENTA "\033[35m"
# define CYAN "\033[36m"
# define RESET "\033[0m"

// Pipex

void	execute_command(char *cmd_raw, char **env);
void	pipex(int fd_in, int fd_out, char **cmd, char **env);

// Pipex_utils

void	exit_error(char *msg, int status, int custom);
int		open_file(const char *file, int i_o);
void	redirect_fd(int fd, int i_o);
void	close_fd(int fd1, int fd2);

// Pipex_utils2

char	*parse_env(char **env);
void	append_slash(char **path);
int		free_array(char **args);

#endif
