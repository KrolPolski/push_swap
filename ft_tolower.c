/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rboudwin <rboudwin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 18:48:24 by rboudwin          #+#    #+#             */
/*   Updated: 2023/10/23 18:48:54 by rboudwin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	ft_tolower(char c)
{
	if (c >= 65 && c <= 90)
		return (c + 32);
	else
		return (c);
}
/*
#include <stdio.h>
int	main(void)
{
	char c;
	char result;

	c = 'D';
	result = ft_tolower(c);
	printf("The letter '%c' is now '%c'", c, result);
}*/
