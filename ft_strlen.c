/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rboudwin <rboudwin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 18:43:41 by rboudwin          #+#    #+#             */
/*   Updated: 2023/10/23 18:50:27 by rboudwin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlen(const char *s)
{
	int	i;
	int	length;

	i = 0;
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
	int length;

	length = ft_strlen(string);
	printf("The string '%s' is '%d' characters long.\n", string, length);
}*/
