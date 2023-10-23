/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rboudwin <rboudwin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 15:00:53 by rboudwin          #+#    #+#             */
/*   Updated: 2023/10/23 15:10:38 by rboudwin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isascii(int c)
{
	if (c >= 0 && c <= 127)
		return (1);
	else
		return (0);
}
/*
#include <stdio.h>
int	main(void)
{
	int	c;
	int	result;

	c = 128;
	result = ft_isascii(c);
	printf("ft_isascii(%d) returns a result of %d \n", c, result);
}*/
