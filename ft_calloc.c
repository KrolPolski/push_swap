/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rboudwin <rboudwin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 09:46:24 by rboudwin          #+#    #+#             */
/*   Updated: 2023/11/06 10:44:29 by rboudwin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;
	size_t	malloc_size;

	malloc_size = count * size;
	if (count != 0 && malloc_size / count != size)
		return (NULL);
	ptr = (malloc(malloc_size));
	if (ptr == NULL)
		return (NULL);
	ft_bzero(ptr, malloc_size);
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
