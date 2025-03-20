/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acosi <acosi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 12:24:23 by acosi             #+#    #+#             */
/*   Updated: 2025/03/20 19:33:25 by acosi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

/*	exit_error :
		In case of error, prints an error message and exit the program.
		status = 0 -> successful program termination
		status = 1 -> an error occured
*/

void	exit_error(char *msg, int status, int custom)
{
	if (msg == NULL)
		exit(status);
	if (custom == 1)
	{
		ft_putstr_fd(RED "Error: " RESET, 2);
		ft_putstr_fd(msg, 2);
		ft_putstr_fd(YELLOW "Usage: " RESET, 2);
		ft_putstr_fd("./pipex <" BLUE, 2);
		ft_putstr_fd("input_file" RESET, 2);
		ft_putstr_fd("> <" BLUE, 2);
		ft_putstr_fd("command1" RESET, 2);
		ft_putstr_fd("> <" BLUE, 2);
		ft_putstr_fd("command2" RESET, 2);
		ft_putstr_fd("> <" BLUE, 2);
		ft_putstr_fd("output_file" RESET, 2);
		ft_putstr_fd(">\n", 2);
	}
	else
		perror(msg);
	exit(status);
}

/*	open_file :
		Opens a file with the given file descriptor.
		The input file is opened in read-only mode in fd1.
		The outpout file is opened in write-only mode in fd2. The outpout file will
		be created if non-existent, its content truncated (i.e. replaced) if it
		already exists, and is given read and write permissions for the owner (6),
		and read-only permissions for the group and others (44).
*/

int	open_file(const char *file, int i_o)
{
	int	fd;

	fd = -1;
	if (i_o == INPUT)
	{
		fd = open(file, O_RDONLY);
		if (fd == -1)
			exit_error("open", EXIT_FAILURE, 0);
	}
	else if (i_o == OUTPUT)
	{
		fd = open(file, O_WRONLY | O_CREAT | O_TRUNC, 0644);
		if (fd == -1)
			exit_error("open", EXIT_FAILURE, 0);
	}
	return (fd);
}

/*	redirect_fd :
		Uses the dup2() function to redirect one fd to another.
		The 2nd fd will be closed and then adjusted to refer to
		the same open file description as the 1st fd.
*/

void	redirect_fd(int fd, int i_o)
{
	if (i_o == STDIN)
	{
		if (dup2(fd, STDIN_FILENO) == -1)
			exit_error("dup2", EXIT_FAILURE, 0);
	}
	else if (i_o == STDOUT)
	{
		if (dup2(fd, STDOUT_FILENO) == -1)
			exit_error("dup2", EXIT_FAILURE, 0);
	}
}

// Closes two fd and exits the program if an error occurs.

void	close_fd(int fd1, int fd2)
{
	if (close(fd1) == -1 || close(fd2) == -1)
		exit_error("close", EXIT_FAILURE, 0);
}
