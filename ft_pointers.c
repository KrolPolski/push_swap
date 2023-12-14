/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pointers.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rboudwin <rboudwin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 16:04:57 by rboudwin          #+#    #+#             */
/*   Updated: 2023/11/18 16:41:12 by rboudwin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putpointer(unsigned long n, int caps, int *len)
{
	int	a;

	a = 0;
	return (ft_puthex_converter(n, caps, len, a));
}

int	ft_fetch_pointer(va_list *args, int *len, int a)
{
	void			*ptr;
	unsigned long	ptr_long;

	ptr = va_arg(*args, void *);
	ptr_long = (unsigned long)ptr;
	a = ft_putstr_fd("0x", 1);
	if (a == -1)
		return (a);
	*len = (*len) + 2;
	a = ft_putpointer(ptr_long, 0, len);
	return (a);
}
