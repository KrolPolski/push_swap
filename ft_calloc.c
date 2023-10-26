/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rboudwin <rboudwin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 09:46:24 by rboudwin          #+#    #+#             */
/*   Updated: 2023/10/26 10:17:08 by rboudwin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;

	ptr = (malloc(count * size));
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
