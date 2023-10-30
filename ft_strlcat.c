/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rboudwin <rboudwin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 15:35:06 by rboudwin          #+#    #+#             */
/*   Updated: 2023/10/30 17:18:45 by rboudwin         ###   ########.fr       */
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
	if (dstsize <= dstlength || max < 0)
		return (dstsize + srclength);
	i = 0;
	j = 0;
	while (dst[j] != '\0')
		j++;
	while (src[i] != '\0' && i < max - 1)
	{
		dst[j] = src[i];
		i++;
		j++;
	}
	dst[j] = '\0';
	return (srclength + dstlength);
}
