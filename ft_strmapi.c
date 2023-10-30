/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rboudwin <rboudwin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 14:23:25 by rboudwin          #+#    #+#             */
/*   Updated: 2023/10/30 11:58:17 by rboudwin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*char static	ft_test_cipher(unsigned int x, char c)
{
	if (x % 2 == 0)
		return (c - 1);
	else
		return (c + 1);
}*/

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*tmp_str;
	int		i;
	int		length;

	i = 0;
	length = ft_strlen(s);
	tmp_str = malloc(length + 1);
	if (tmp_str == NULL)
		return (NULL);
	while (s[i] != '\0')
	{
		tmp_str[i] = f(i, s[i]);
		i++;
	}
	tmp_str[i] = '\0';
	return (tmp_str);
}
/*
#include <stdio.h>

int main(void)
{
    char const s[] = "so long and thanks for all the fish";
	char *result;

	printf("String before: '%s'\n", s);
	result = ft_strmapi(s, *ft_test_cipher);
	printf("String after: '%s'\n", result);
	free(result); 
}*/
