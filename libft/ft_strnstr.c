/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acosi <acosi@student.42nice.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 15:29:04 by acosi             #+#    #+#             */
/*   Updated: 2023/06/08 21:57:19 by acosi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
	DESCRIPTION :
	The function ft_strnstr searches the first n bytes of the given string
	'str' for the first occurence of the full string 'to_find'.
	Characters that appear after \0 are not searched.

	RETURN VALUE :
	A pointer to the first character of the first occurrence of s2.
	A pointer to 'str' if 'to_find' is empty.
	NULL if 'to_find' occurs nowhere in 'str'.
*/

#include "libft.h"

char	*ft_strnstr(const char *str, const char *to_find, size_t n)
{
	size_t	i;
	size_t	j;
	size_t	len;

	i = 0;
	len = ft_strlen(to_find);
	if (len == 0 || str == to_find)
		return ((char *)str);
	if (!str && n == 0)
		return (NULL);
	while (str[i] && (i < n))
	{
		j = 0;
		while ((to_find[j] == str[i + j]) && (i + j < n))
		{
			if (to_find[j + 1] == '\0')
				return ((char *)&str[i]);
			j++;
		}
		i++;
	}
	return (NULL);
}
