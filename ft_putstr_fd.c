/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rboudwin <rboudwin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 10:43:28 by rboudwin          #+#    #+#             */
/*   Updated: 2023/11/01 13:38:26 by rboudwin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	int	length;

	if (s == NULL)
		return ;
	length = ft_strlen(s);
	write(fd, s, length);
}
/*
#include <fcntl.h>

int	main(void)

{
	int	file_descriptor;

	file_descriptor = open("./file", O_CREAT | O_RDWR | O_APPEND);
	ft_putstr_fd("So long and thanks for all the fish", file_descriptor);
	close(file_descriptor);
}*/
