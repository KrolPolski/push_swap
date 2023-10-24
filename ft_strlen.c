/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rboudwin <rboudwin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 18:43:41 by rboudwin          #+#    #+#             */
/*   Updated: 2023/10/24 11:55:15 by rboudwin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>

size_t	ft_strlen(const char *s)
{
	int		i;
	size_t	length;

	i = 0;
	length = 0;
	while (s[i] != '\0')
	{
		length++;
		i++;
	}
	return (length);
}
/*
#include <stdio.h>

int	main(void)
{
	char string[] = "fish";
	size_t length;

	length = ft_strlen(string);
	printf("The string '%s' is '%zu' characters long.\n", string, length);

}*/
