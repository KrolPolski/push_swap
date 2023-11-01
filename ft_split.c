/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rboudwin <rboudwin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 15:48:23 by rboudwin          #+#    #+#             */
/*   Updated: 2023/11/01 13:48:27 by rboudwin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_split(char const *s, char c)
{
	int		i;
	int		j;
	int		k;
	char	**str_array;

	i = 0;
	j = 0;
	k = 0;
	if (s == NULL)
		return (NULL);
	if (s[0] == '\0')
		return (NULL);

	str_array = malloc(ft_strlen(s) + 1);
	str_array[0] = malloc(ft_strlen(s) + 1);
	if (c == '\0')
		{
			ft_strlcpy(str_array[0], s, ft_strlen(s));
			str_array[1] = malloc(1);
			str_array[1][0] = '\0';
			return str_array;
		}
	while (s[i] != '\0')
	{
		if (s[i] != c)
			str_array[j][k++] = s[i];
		else if (s[i] == c && s[i + 1] != c && str_array[j][0] != '\0')
		{
			str_array[j][k] = '\0';
			k = 0;
			str_array[++j] = malloc(ft_strlen(s) + 1);
		}
		i++;
	}
	str_array[j][k] = '\0';
	j++;
	str_array[j] = NULL;
	return (str_array);
}
/*
#include <stdio.h>

int	main(void)
{
//	char	str[] = ",,,So long,,, and thanks,,, for all, the fish,,,";
	char    str[] = "   So-long    and-thanks    for-all    the-fish    ";
//	char	c = ',';
	char    c = ' ';
	char	**str_array;

	str_array = ft_split(str, c);
	printf("'%s' split by '%c' results in:\n", str, c);
	printf("'%s' '%s' '%s' '%s' \n", str_array[0], str_array[1],
		str_array[2], str_array[3]);
	free(str_array[0]);
	free(str_array[1]);
	free(str_array[2]);
	free(str_array[3]);
	free(str_array);
}
*/