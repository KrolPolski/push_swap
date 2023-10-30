/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rboudwin <rboudwin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 15:35:06 by rboudwin          #+#    #+#             */
/*   Updated: 2023/10/30 14:55:23 by rboudwin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	srclength;
	size_t	dstlength;
	size_t	i;
	size_t	j;
	size_t	max;

	if (dstsize == 0)
		return (0);
	srclength = ft_strlen(src);
	dstlength = ft_strlen(dst);
	max = dstsize - dstlength;
	if (dstsize < dstlength)
		return (dstlength);
	i = 0;
	j = 0;
	while (dst[j] != '\0')
	{
		j++;
	}
	while (src[i] != '\0' && i < max)
	{
		dst[j] = src[i];
		i++;
		j++;
	}
	dst[j] = '\0';
	return (srclength + dstsize);
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
