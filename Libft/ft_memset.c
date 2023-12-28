/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rboudwin <rboudwin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 11:59:17 by rboudwin          #+#    #+#             */
/*   Updated: 2023/10/25 15:55:51 by rboudwin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t	i;
	char	*ptr;

	i = 0;
	ptr = b;
	while (i < len)
	{
		ptr[i] = c;
		i++;
	}
	return (b);
}

/*
#include <stdio.h>
int	main(void)
{
	char	string[] = "Fish";
	int		c = 'd';
	void	*ptr;
	
	printf("The string was '%s'\n", string);
	ptr = ft_memset(string, c, 4);
	printf("But now it is '%s'\n", string);
}*/
