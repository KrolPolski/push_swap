/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rboudwin <rboudwin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 18:34:25 by rboudwin          #+#    #+#             */
/*   Updated: 2023/11/06 09:58:19 by rboudwin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	a;

	i = 0;
	a = (char)c;
	while (s[i] != a && s[i] != '\0')
		i++;
	if (s[i] == a)
		return ((char *)&s[i]);
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
