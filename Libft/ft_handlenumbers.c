/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handlenumbers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rboudwin <rboudwin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 15:32:48 by rboudwin          #+#    #+#             */
/*   Updated: 2023/11/18 16:41:44 by rboudwin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_unsigned(unsigned int n, int fd, int *len, int a)
{
	if (n >= 10)
	{
		a = ft_putnbr_unsigned(n / 10, fd, len, a);
		if (a == -1)
			return (a);
		n = n % 10;
	}
	if (n < 10)
	{
		a = ft_putchar_fd(n + '0', fd);
		if (a == -1)
			return (a);
		(*len)++;
	}
	return (a);
}

int	ft_puthex_converter(unsigned long n, int caps, int *len, int a)
{
	if (n >= 16)
	{
		a = ft_puthex_converter(n / 16, caps, len, a);
		if (a == -1)
			return (a);
		n = n % 16;
	}
	if (n < 16)
	{
		if (n < 10)
			a = ft_putchar_fd(n + '0', 1);
		else
		{
			if (caps == 0)
				a = ft_putchar_fd(n + 87, 1);
			else
				a = ft_putchar_fd(n + 55, 1);
		}
		(*len)++;
		if (a == -1)
			return (a);
	}
	return (0);
}

int	ft_puthex(unsigned int n, int caps, int *len)
{
	int	a;

	a = 0;
	return (ft_puthex_converter(n, caps, len, a));
}

int	ft_log10(int n)
{
	int	result;

	result = 0;
	while (n / 10 != 0)
	{
		result++;
		n = n / 10;
	}
	return (result);
}

int	ft_fetch_integer(va_list *args, int *len)
{
	int	n;
	int	a;

	n = va_arg(*args, int);
	if (n == -2147483648)
	{
		a = ft_putstr_fd("-2147483648", 1);
		if (a == -1)
			return (a);
		*len = (*len) + 11;
		return (a);
	}
	if (n < 0)
	{
		(*len)++;
		n = -n;
		a = ft_putchar_fd('-', 1);
		if (a == -1)
			return (a);
	}
	a = ft_putnbr_fd(n, 1);
	if (a == -1)
		return (a);
	(*len) = (*len) + 1 + ft_log10(n);
	return (a);
}
