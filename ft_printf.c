/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rboudwin <rboudwin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 15:32:55 by rboudwin          #+#    #+#             */
/*   Updated: 2023/11/18 16:44:49 by rboudwin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_fetch_string(va_list *args, int *len, int a)
{
	char	*str;

	str = va_arg(*args, char *);
	if (str == NULL)
	{
		a = ft_putstr_fd("(null)", 1);
		*len = (*len) + 6;
	}
	else
	{
		a = ft_putstr_fd(str, 1);
		*len = (*len) + ft_strlen(str);
	}
	return (a);
}

int	ft_percent_or_char(char const *c, int *i, va_list *args, int *len)
{
	int	a;

	a = -1;
	if (c[(*i)] == '%')
	{
		a = ft_putchar_fd('%', 1);
		(*len)++;
	}
	else if (c[*i] == 'c')
	{
		a = ft_putchar_fd(va_arg(*args, int), 1);
		(*len)++;
	}
	return (a);
}

int	ft_identify_data_type(char const *c, int i, va_list *args, int *len)
{
	int	a;

	a = -1;
	i++;
	if (c[i] == '%' || c[i] == 'c')
		a = ft_percent_or_char(c, &i, args, len);
	else if (c[i] == 'd' || c[i] == 'i')
		a = (ft_fetch_integer(args, len));
	else if (c[i] == 'p')
		a = (ft_fetch_pointer(args, len, 0));
	else if (c[i] == 's')
		a = (ft_fetch_string(args, len, 0));
	else if (c[i] == 'u')
		a = ft_putnbr_unsigned(va_arg(*args, unsigned int), 1, len, 0);
	else if (c[i] == 'x')
		a = ft_puthex(va_arg(*args, int), 0, len);
	else if (c[i] == 'X')
		a = ft_puthex(va_arg(*args, int), 1, len);
	if (a == -1)
		i = a;
	return (i);
}

int	ft_printf(const char *c, ...)
{
	int		a;
	int		i;
	va_list	args;
	int		len;

	i = 0;
	len = 0;
	va_start(args, c);
	while (c[i] != '\0')
	{
		if (c[i] == '%')
			i = ft_identify_data_type(c, i, &args, &len);
		else
		{
			a = ft_putchar_fd(c[i], 1);
			if (a == -1)
				return (a);
			len++;
		}
		if (i == -1)
			return (i);
		i++;
	}
	va_end(args);
	return (len);
}
