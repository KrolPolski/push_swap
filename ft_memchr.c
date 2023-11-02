/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rboudwin <rboudwin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 10:21:52 by rboudwin          #+#    #+#             */
/*   Updated: 2023/11/02 09:32:08 by rboudwin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	char	*str;
	size_t	i;

	i = 0;
	str = (char *)s;
	while (str[i] != '\0' && str[i] != c && i < n)
		i++;
	if (str[i] == c)
		return (&str[i]);
	else
		return (NULL);
}
/*
#include <stdio.h>
int	main(void)
{
	char string[] = "So long and thanks";
	char search = 'l';
	void *ptr;

	ptr = ft_memchr(string, search, 18);
	printf("The character '%c' is found in '%s' at '%p'", search, string, ptr);
}*/
