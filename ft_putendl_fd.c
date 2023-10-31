/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rboudwin <rboudwin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 10:53:23 by rboudwin          #+#    #+#             */
/*   Updated: 2023/10/31 13:21:13 by rboudwin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	ft_putendl_fd(unsigned char *s, int fd)
{
	int	length;
	char	new_line;

	new_line = '\n';
	length = ft_strlen(s);
	write(fd, s, length);
	write(fd, &new_line, 1);
}

/*
#include <fcntl.h>

int	main(void)

{
	int	file_descriptor;

	file_descriptor = open("./file", O_CREAT | O_RDWR | O_APPEND);
	ft_putendl_fd("So long and thanks for all the fish", file_descriptor);
	close(file_descriptor);
}*/
