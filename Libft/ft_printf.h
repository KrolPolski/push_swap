/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rboudwin <rboudwin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 14:28:58 by rboudwin          #+#    #+#             */
/*   Updated: 2023/11/18 16:43:28 by rboudwin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include "libft.h"

int	ft_fetch_integer(va_list *args, int *len);
int	ft_fetch_pointer(va_list *args, int *len, int a);
int	ft_identify_data_type(char const *c, int i, va_list *args, int *len);
int	ft_log10(int n);
int	ft_printf(const char *c, ...);
int	ft_puthex(unsigned int n, int caps, int *len);
int	ft_puthex_converter(unsigned long n, int caps, int *len, int a);
int	ft_putnbr_unsigned(unsigned int n, int fd, int *len, int a);
int	ft_putpointer(unsigned long n, int caps, int *len);

#endif
