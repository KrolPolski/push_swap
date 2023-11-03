/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rboudwin <rboudwin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 09:46:24 by rboudwin          #+#    #+#             */
/*   Updated: 2023/11/03 14:12:47 by rboudwin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;

	if (size < 4294967296 && count < 4294967296 && size > 0 && count > 0)
		ptr = (malloc(count * size));
	else
		return (NULL);
	if (ptr == NULL)
		return (NULL);
	ft_bzero(ptr, count * size);
	return (ptr);
}
/*
#include <stdio.h>

int	main(void)
{
	char	*ptr;

	ptr = ft_calloc(1, 10);
	if (ptr != NULL)
		printf("Calloc successful");
	else
		printf("Calloc failed");
	free(ptr);
}*/
