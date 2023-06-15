/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acosi <acosi@student.42nice.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 15:49:49 by acosi             #+#    #+#             */
/*   Updated: 2023/06/08 21:48:27 by acosi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
	DESCRIPTION :
	The function ft_strlcpy copies up to n - 1 characters from the given
	string src to the given string dst, nul-terminating the result.

	Note : space for the terminating \0 character must be included in n.

	RETURN VALUE :
	The total length of the string that it tried to create : the length of
	src, with the goal to facilitate truncaction detection.
*/

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t n)
{
	size_t	i;
	size_t	src_len;

	i = 0;
	src_len = ft_strlen (src);
	if (!n)
		return (src_len);
	while (src[i] != '\0' && i < n)
	{
		dst[i] = src[i];
		i++;
	}
	if (n <= src_len)
		dst[n - 1] = '\0';
	else if (n != 0)
		dst[i] = '\0';
	return (src_len);
}
