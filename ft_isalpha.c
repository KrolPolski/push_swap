/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rboudwin <rboudwin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 13:40:36 by rboudwin          #+#    #+#             */
/*   Updated: 2023/10/23 14:40:28 by rboudwin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// 65 - 90 is uppercase
// 97 - 122 is lowercase
int	ft_isalpha(int c)
{
	if ((c >= 65 && c <= 90) || (c >= 97 && c <= 122))
		return (1);
	else
		return (0);
}
/*
#include <stdio.h>
#include <ctype.h>
int main(void)
{
	int result;
	int c;
	int checkresult;

	c = 90;
	result = ft_isalpha(c);
	printf("ft_isalpha(%d) returns the value of %d\n", c, result);
	checkresult = isalpha(c);
	printf("isalpha(%d) returns the value of %d\n", c, checkresult);
}*/
