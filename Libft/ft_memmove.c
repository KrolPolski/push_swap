/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rboudwin <rboudwin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 14:26:37 by rboudwin          #+#    #+#             */
/*   Updated: 2023/10/30 13:47:13 by rboudwin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t		i;
	char		*destination;
	const char	*source;

	destination = dst;
	source = src;
	i = 0;
	if (dst == NULL && src == NULL)
		return (NULL);
	while (dst < src && i < len)
	{
		destination[i] = source[i];
		i++;
	}
	while (dst > src && len > 0)
	{
		destination[len - 1] = source[len - 1];
		len--;
	}
	return ((void *)destination);
}
/*
#include <stdio.h>

int	main(void)
{
	const char	src[] = "Fish";
	char		dst[] = "Duckhunter";
	void		*result;
	
	printf("The src is '%s' and the dst is '%s':\n", src, dst);
	result = ft_memmove(dst, src, 4);
	printf("Now the dst is: '%s'\n", dst);
}
*/
