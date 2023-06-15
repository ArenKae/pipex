/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acosi <acosi@student.42nice.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 13:55:02 by acosi             #+#    #+#             */
/*   Updated: 2023/06/08 22:40:22 by acosi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

// Parses the environment variables and returns the PATH.

char	*parse_env(char **env)
{
	int		i;
	char	*path;

	i = 0;
	while (env[i] != NULL && env[i][0] != '\0')
	{
		path = ft_strnstr(env[i], "PATH=", 5);
		if (path)
		{
			path = ft_substr(path, 5, ft_strlen(path) - 5);
			break ;
		}
		i++;
	}
	return (path);
}

// Adds a '/' character at the end of each element of PATH
// to get correct formatting for execve() function calls.

void	append_slash(char **path)
{
	int		i;
	int		len;
	char	*new_path;

	i = 0;
	while (path[i])
	{
		len = ft_strlen(path[i]);
		new_path = malloc(sizeof(char) * (len + 2));
		ft_strlcpy(new_path, path[i], len + 1);
		new_path[len] = '/';
		new_path[len + 1] = '\0';
		free(path[i]);
		path[i] = new_path;
		i++;
	}
}

// Frees an entire array of strings.

int	free_array(char **args)
{
	int	i;

	i = 0;
	while (args[i])
	{
		free(args[i]);
		i++;
	}
	free(args);
	return (0);
}
