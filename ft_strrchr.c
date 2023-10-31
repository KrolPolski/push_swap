/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rboudwin <rboudwin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 10:05:44 by rboudwin          #+#    #+#             */
/*   Updated: 2023/10/31 13:32:00 by rboudwin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned char	*ft_strrchr(const unsigned char *s, int c)
{
	size_t	i;

	if (s[0] == '\0')
		return (NULL);
	i = ft_strlen(s);
	while (s[i] != c && i != 0)
		i--;
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
	ptr = ft_strrchr(string, c);
	printf("The character '%c' is found at: %p which is %c", c, ptr, *ptr); 
}*/
