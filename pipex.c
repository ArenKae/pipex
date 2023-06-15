/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acosi <acosi@student.42nice.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 12:06:37 by acosi             #+#    #+#             */
/*   Updated: 2023/06/12 15:29:18 by acosi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

/*	execute_command :
		Uses the PATH retrieved from the environment variables and formats it
		for use in execve(). Also formats the command to execute into an array for the
		same reasons.
		The function will loop through every possible PATH until it finds a matching 
		valid executable. On success, execve() does not return, and the process
		calling it is replaced by the program being executed.
*/

void	execute_command(char *cmd_raw, char **env)
{
	char	*path_raw;
	char	**my_path;
	char	**cmd_clean;
	char	*cmd_path;
	int		i;

	path_raw = parse_env(env);
	my_path = ft_split(path_raw, ':');
	free(path_raw);
	append_slash(my_path);
	cmd_clean = ft_split(cmd_raw, ' ');
	i = -1;
	while (my_path[++i])
	{
		cmd_path = ft_strjoin(my_path[i], cmd_clean[0]);
		execve(cmd_path, cmd_clean, env);
		free(cmd_path);
	}
	free_array(my_path);
	free_array(cmd_clean);
}

/*	pipex :
		The pipe() function creates a unidirectional pipe, which is a communication
		channel that allows one-way data flow between processes. It creates a pair of
		fd: pipefd[0] to read from the pipe and pipefd[1] for writing to the pipe. 
		The fork() function creates a new child process and gives it a new PID.
		fork() returns 0 while in the child process. Else, it returns the PID of
		the child while in the parent process. Both execute at the same time.
		Each command to execute needs a stdin (input) and returns an outpout
		(to stdout). We use the dup2() function to redirect stdin and stdout for the
		2 files fd and the pipe. Finally, we use execve() to execute the commands
		specified as arguments.
*/

void	pipex(int fd1, int fd2, char **cmd, char **env)
{
	int		pipefd[2];
	pid_t	pid;

	if (pipe(pipefd) == -1)
		exit_error("pipe", EXIT_FAILURE);
	pid = fork();
	if (pid == -1)
		exit_error("fork", EXIT_FAILURE);
	if (pid == CHILD)
	{
		redirect_fd(fd1, STDIN);
		redirect_fd(pipefd[WRITE], STDOUT);
		close_fd(pipefd[WRITE], pipefd[READ]);
		execute_command(cmd[2], env);
	}
	else
	{
		redirect_fd(pipefd[READ], STDIN);
		redirect_fd(fd2, STDOUT);
		close_fd(pipefd[READ], pipefd[WRITE]);
		execute_command(cmd[3], env);
	}
	waitpid(pid, NULL, 0);
}

int	main(int argc, char **argv, char **env)
{
	int	fd1;
	int	fd2;

	if (argc != 5)
		exit_error("Invalid number of arguments !", EXIT_FAILURE);
	fd1 = open_file(argv[1], INPUT);
	fd2 = open_file(argv[4], OUTPUT);
	pipex(fd1, fd2, argv, env);
	close_fd(fd1, fd2);
	return (0);
}
