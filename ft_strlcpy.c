/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rboudwin <rboudwin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 14:38:54 by rboudwin          #+#    #+#             */
/*   Updated: 2023/10/24 15:31:21 by rboudwin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

size_t static	ft_strlen(const char *s)
{
	int		i;
	size_t	length;

	i = 0;
	length = 0;
	while (s[i] != '\0')
	{
		length++;
		i++;
	}
	return (length);
}

size_t	ft_strlcpy(char *restrict dst, const char *restrict src, size_t dstsize)
{
	size_t	i;

	i = 0;
	if (dstsize == 0)
		return (ft_strlen(src));
	while (i < dstsize - 1 && src[i] != '\0')
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (ft_strlen(src));
}
/*
#include <stdio.h>

int	main(void)
{
	char *restrict	src;
	char source[] = "Duckhunter";
	char *restrict	dst;
	char destination[] = "Fisherman";
	size_t	dstsize;
	size_t	result;
	
	src = source;
	dst = destination;
	dstsize = 10;
	printf("The src is '%s' and the dst is '%s'\n", src, dst);
	result = ft_strlcpy(dst, src, dstsize);
	printf("The dst is now '%s'\n and the return value is '%zu'", dst, result);
}*/
