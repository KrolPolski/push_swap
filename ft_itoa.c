/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rboudwin <rboudwin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 10:50:04 by rboudwin          #+#    #+#             */
/*   Updated: 2023/10/31 13:18:00 by rboudwin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static int	ft_power(int a, int exp)
{
	int	i;
	int	result;

	result = a;
	i = 1;
	if (exp == 0)
		return (1);
	if (exp == 1)
		return (a);
	while (i < exp)
	{
		result = result * a;
		i++;
	}
	return (result);
}

static unsigned char	*ft_conversion(int k, int i, unsigned char *str, int n)
{
	while (k > 0)
	{
		str[i] = (n / ft_power(10, k)) + 48;
		n = n - ((str[i] - 48) * ft_power(10, k));
		i++;
		k--;
	}
	str[i++] = (n % 10) + 48;
	str[i] = '\0';
	return (str);
}

static unsigned char	*ft_handle_malloc(int digits, int n)
{
	unsigned char	*str;

	if (n < 0)
		str = malloc(digits + 2);
	else
		str = malloc(digits + 1);
	return (str);
}

unsigned char	*ft_itoa(int n)
{
	int		i;
	int		k;
	int		digits;
	unsigned char	*str;

	i = 0;
	digits = 1;
	k = n;
	while (k / 10 != 0)
	{
		digits++;
		k = k / 10;
	}
	k = digits - 1;
	str = ft_handle_malloc(digits, n);
	if (str == NULL)
		return (NULL);
	if (n == -2147483648)
		return (ft_strdup((unsigned char*)"-2147483648"));
	if (n < 0)
	{
		str[i++] = '-';
		n = -n;
	}
	return (ft_conversion(k, i, str, n));
}
/*
#include <stdio.h>

int	main(void)
{
	int		n;
	char	*str;

	n = -214748348;
	str = ft_itoa(n);
	printf("'%d' represented as a string is '%s'", n, str);
	free(str);
}*/
