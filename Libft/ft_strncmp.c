/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rboudwin <rboudwin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 10:11:01 by rboudwin          #+#    #+#             */
/*   Updated: 2023/11/03 10:02:53 by rboudwin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned int	i;
	unsigned char	*str1;
	unsigned char	*str2;

	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	i = 0;
	while (i < n && (str1[i] != '\0' || str2[i] != '\0'))
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
	char	string[11] = "duckh\0unter";
	char	string2[11] = "duckisher";
	int		value;

	value = ft_strncmp(string, string2, 6);
	printf("We expect the answer to be the difference between the \n");
	printf("first non-matching character in the string from the table.");
    printf("\n The difference between %s and %s is:", string, string2);
	printf("%d \n", value);
}*/
