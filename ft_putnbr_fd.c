/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rboudwin <rboudwin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 10:57:46 by rboudwin          #+#    #+#             */
/*   Updated: 2023/11/02 14:21:38 by rboudwin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_putchar(int fd, char c)
{
	write(fd, &c, 1);
}

void	ft_putnbr_fd(int n, int fd)
{
	if (n == -2147483648)
	{
		write(fd, "-2147483648", 11);
		return ;
	}
	if (n < 0)
	{
		ft_putchar(fd, '-');
		n = -n;
	}
	if (n >= 10)
	{
		ft_putnbr_fd(n / 10, fd);
		n = n % 10;
	}
	if (n < 10)
		ft_putchar(fd, n + '0');
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
