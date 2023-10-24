/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rboudwin <rboudwin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 12:16:31 by rboudwin          #+#    #+#             */
/*   Updated: 2023/10/24 12:22:07 by rboudwin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>

void	ft_bzero(void *s, size_t n)
{
	size_t	i;
	char	*ptr;

	i = 0;
	ptr = s;
	while (i < n)
	{
		ptr[i] = '\0';
		i++;
	}
}
/*
#include <stdio.h>
int	main(void)
{
	char string[] = "fish";
	
	printf("The string was: '%s'\n", string);
	ft_bzero(string, 4);
	printf("But now it is: '%s'\n", string);
}*/
