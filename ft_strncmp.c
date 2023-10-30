/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rboudwin <rboudwin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 10:11:01 by rboudwin          #+#    #+#             */
/*   Updated: 2023/10/30 14:13:55 by rboudwin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_strncmp(const unsigned char *s1, const unsigned char *s2, size_t n)
{
	unsigned int	i;

	i = 0;
	while (i < n && (s1[i] != '\0' || s2[i] != '\0'))
	{
		if (s1[i] == s2[i])
			i++;
		else
			return (s1[i] - s2[i]);
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
