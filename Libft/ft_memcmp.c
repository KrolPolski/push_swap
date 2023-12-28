/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rboudwin <rboudwin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 10:36:31 by rboudwin          #+#    #+#             */
/*   Updated: 2023/10/30 13:58:39 by rboudwin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*str1;
	unsigned char	*str2;
	size_t			i;

	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	i = 0;
	while (i < n)
	{
		if (str1[i] == str2[i])
			i++;
		else
			return (str1[i] - str2[i]);
	}
	return (0);
}
/*
#include <stdio.h>

int	main(void)
{
	char 	str1[] = "fish";
	char 	str2[] = "fisherman";
	size_t	n;
	int		result;
	
	n = 5;
	result = ft_memcmp(str1, str2, n); 
	printf("The difference between '%s' and '%s' \n", str1, str2); 
	printf("to '%zu' places is '%d'\n", n, result);
}*/
