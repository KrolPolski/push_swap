/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rboudwin <rboudwin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 18:34:25 by rboudwin          #+#    #+#             */
/*   Updated: 2023/10/31 13:32:44 by rboudwin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

unsigned char	*ft_strchr(const unsigned char *s, int c)
{
	int	i;

	i = 0;
	while (s[i] != c && s[i] != '\0')
		i++;
	if (s[i] == c)
		return ((unsigned char *)&s[i]);
	else
		return (NULL);
}
/*
#include <stdio.h>
int	main(void)
{
	int c;
	const char string[] = "Fish";
	char *ptr;

	c = 'i';
	ptr = ft_strchr(string, c);
	printf("The character '%c' is found at: %p which is %c", c, ptr, *ptr); 
}*/
