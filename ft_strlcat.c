/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rboudwin <rboudwin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 15:35:06 by rboudwin          #+#    #+#             */
/*   Updated: 2023/10/25 15:49:38 by rboudwin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	srclength;
	size_t	dstlength;
	size_t	i;
	size_t	j;

	srclength = ft_strlen(src);
	dstlength = ft_strlen(dst);
	i = 0;
	j = 0;
	while (dst[j] != '\0')
	{
		j++;
	}
	while (src[i] != '\0' && i < dstsize)
	{
		dst[j] = src[i];
		i++;
		j++;
	}
	dst[j] = '\0';
	return (srclength + dstlength);
}
/*
#include <stdio.h>
int	main(void)
{
	char source[] = "erman";
	char dest[13] = "Fish";
	size_t result;
	printf("The source was '%s' and the destination was '%s'\n", source, dest);
	result = ft_strlcat(dest, source, 13);
	printf("The destination is now '%s' and the return is '%zu'\n", dest, result);
}*/
