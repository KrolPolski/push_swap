/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rboudwin <rboudwin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 10:57:46 by rboudwin          #+#    #+#             */
/*   Updated: 2023/11/01 12:39:13 by rboudwin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	int		length;
	char	*string;

	string = ft_itoa(n);
	length = ft_strlen(string);
	write(fd, string, length);
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
