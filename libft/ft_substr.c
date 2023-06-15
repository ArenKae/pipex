/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acosi <acosi@student.42nice.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 14:50:50 by acosi             #+#    #+#             */
/*   Updated: 2023/06/08 21:57:57 by acosi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
	DESCRIPTION :
	The function ft_substr extracts a substring from the given string by
	allocating sufficient memory for the new string starting at index start
	and ending at len characters.

	RETURN VALUE :
	A pointer to the new string.
	NULL if the memory allocation fails.
*/

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned int	i;
	unsigned int	j;
	char			*cpy;

	if ((size_t)start > ft_strlen(s))
		return (ft_strdup(""));
	i = start;
	j = 0;
	while (s[i++] != '\0')
		j++;
	if (j > (unsigned int)len)
		j = (unsigned int)len;
	cpy = malloc(sizeof(char) * (j + 1));
	if (!cpy)
		return (NULL);
	i = start;
	j = 0;
	while (s[i] != '\0' && (size_t)j < len)
	{
		cpy[j] = s[i];
		i++;
		j++;
	}
	cpy[j] = '\0';
	return (cpy);
}
