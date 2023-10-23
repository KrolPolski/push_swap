/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rboudwin <rboudwin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 13:40:36 by rboudwin          #+#    #+#             */
/*   Updated: 2023/10/23 13:52:32 by rboudwin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int ft_isalpha(int c)
{
	if ((c >= 65 && c <= 90) || (c >= 97 && c <= 122))
		return (1);
	else
		return (0);
// 65 - 90 is uppercase
// 97 - 122 is lowercase
}

#include <stdio.h>
int main(void)
{
	int result;
	int c;

	c = 122;
	result = ft_isalpha(c);
	printf("isalpha(%d) returns the value of %d)", c, result);
}
