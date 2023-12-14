/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rboudwin <rboudwin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 10:57:46 by rboudwin          #+#    #+#             */
/*   Updated: 2023/11/14 15:20:18 by rboudwin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putnbr_fd(int n, int fd)
{
	int	a;

	if (n == -2147483648)
	{
		a = write(fd, "-2147483648", 11);
		return (a);
	}
	if (n < 0)
	{
		a = ft_putchar_fd('-', fd);
		if (a == -1)
			return (a);
		n = -n;
	}
	if (n >= 10)
	{
		a = ft_putnbr_fd(n / 10, fd);
		if (a == -1)
			return (a);
		n = n % 10;
	}
	if (n < 10)
		a = ft_putchar_fd(n + '0', fd);
	return (a);
}
/*

#include <fcntl.h>

int	main(void)

{
	int	file_descriptor;

	file_descriptor = open("./file", O_CREAT | O_RDWR | O_APPEND);
	ft_putnbr_fd(142857, file_descriptor);
	close(file_descriptor);
}*/
