/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acosi <acosi@student.42nice.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 14:27:07 by acosi             #+#    #+#             */
/*   Updated: 2023/06/08 21:36:57 by acosi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
	DESCRIPTION :
	The function ft_strdup duplicates the given string s1 by allocating 
	memory and performing a copy of the given string.

	RETURN VALUE :
	A pointer to the new string. NULL if the memory allocation fails.
*/

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	size_t	i;
	char	*cpy;

	cpy = malloc(sizeof(char) * (ft_strlen(s1) + 1));
	if (!cpy)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		cpy[i] = s1[i];
		i++;
	}
	cpy[i] = '\0';
	return (cpy);
}
