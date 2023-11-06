/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rboudwin <rboudwin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 10:21:52 by rboudwin          #+#    #+#             */
/*   Updated: 2023/11/06 09:50:21 by rboudwin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*str;
	size_t			i;
	unsigned char	d;

	d = c;
	i = 0;
	if (n == 0)
		return (NULL);
	str = (unsigned char *)s;
	while (str[i] != d && i < n - 1)
	{
		i++;
	}
	if (str[i] == d)
		return (&str[i]);
	else
		return (NULL);
}
/*
#include <stdio.h>
int	main(void)
{
	char s[] = {0, 1, 2, 3, 4, 5};
	char *str;

	str = ft_memchr(s, 2, 3);
	printf("'%c'\n", s[2]);
	printf("The result is '%s'", str);
*/
/*	char string[] = "So long and thanks";
	char str[] = "bonjourno";
	char search = 'l';
	void *ptr;

	ptr = ft_memchr(string, search, 18);
	printf("The character '%c' is found in '%s' at '%p'\n", search, string, ptr);
	search = 'n';
	ptr = ft_memchr(str, search, 2);
	printf("The character '%c' is found in '%s' at '%p'\n", search, str, ptr);
*/
//}
