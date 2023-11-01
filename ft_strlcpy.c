/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rboudwin <rboudwin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 14:38:54 by rboudwin          #+#    #+#             */
/*   Updated: 2023/11/01 12:37:08 by rboudwin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
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
	char *src;
	char source[] = "Duckhunter";
	char *dst;
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
