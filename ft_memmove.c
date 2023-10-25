/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rboudwin <rboudwin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 14:26:37 by rboudwin          #+#    #+#             */
/*   Updated: 2023/10/25 15:55:33 by rboudwin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	void		*result;
	size_t		i;
	char		*destination;
	const char	*source;

	destination = dst;
	source = src;
	result = dst;
	i = 0;
	while (i < len)
	{
		destination[i] = source[i];
		i++;
	}
	return (result);
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
