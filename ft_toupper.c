/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rboudwin <rboudwin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 18:47:20 by rboudwin          #+#    #+#             */
/*   Updated: 2023/10/23 18:48:02 by rboudwin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	ft_toupper(char c)
{
	if (c >= 97 && c <= 122)
		return (c - 32);
	else
		return (c);
}
/*
#include <stdio.h>
int	main(void)
{
	char c;
	char result;
	
	c = 'd';
	result = ft_toupper(c);
	printf("The char '%c' should now be uppercase: '%c'", c, result);
}*/
