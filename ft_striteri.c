/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rboudwin <rboudwin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 10:05:32 by rboudwin          #+#    #+#             */
/*   Updated: 2023/10/30 10:19:58 by rboudwin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void static	ft_test_cipher(unsigned int x, char *c)
{
	if (x % 2 == 0)
		(*c -= 1);
	else
		(*c += 1);
}

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	int		i;
	int		length;

	i = 0;
	length = ft_strlen(s);
	while (s[i] != '\0')
	{
		f(i, s + i);
		i++;
	}
	s[i] = '\0';
}
/*
#include <stdio.h>

int	main(void)
{
char s[] = "so long and thanks for all the fish";

	printf("String before: '%s'\n", s);
	ft_striteri(s, *ft_test_cipher);
	printf("String after: '%s'\n", s);
}*/
