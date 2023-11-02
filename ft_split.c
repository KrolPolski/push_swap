/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rboudwin <rboudwin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 15:48:23 by rboudwin          #+#    #+#             */
/*   Updated: 2023/11/02 12:08:29 by rboudwin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
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
	str_array = malloc(ft_strlen(s) + 1);
		if (str_array == NULL)
			return (NULL);
	str_array[0] = malloc(ft_strlen(s) + 1);
		if (str_array[0] == NULL)
		{
			free(str_array);
			return (NULL);
		}
	if (c == '\0')
	{
		ft_strlcpy(str_array[0], s, ft_strlen(s));
		str_array[1] = NULL;
		return (str_array);
	}
	while (s[i] == c && s[i] != '\0')
		i++;
	while (s[i] != '\0')
	{
		if (s[i] != c)
			str_array[j][k++] = s[i];

		else if (s[i] == c && s[i + 1] != c && k != 0)
		{
			str_array[j][k] = '\0';
			k = 0;
			str_array[++j] = malloc(ft_strlen(s) + 1);
			if (str_array[j] == NULL)
			{
				while (k < j)
					free(str_array[k++]);
				free(str_array);
				return (NULL);
			}
		}
		i++;
	}
	str_array[j][k] = '\0';
	if (j == 0)
		j++;
	str_array[j] = NULL;
	return (str_array);
}

//#include <stdio.h>
//#include <string.h>
/*
int	main(void)
{
    char    **expected = (char*[6]){"split  ", "this", "for", "me", "!", NULL};

    char    *s = "split  ||this|for|me|||||!|";
	int             i = 0;
	char    **result = ft_split(s, '|');
    while (result[i]) {
		printf("strcmp(result[%d], *expected) is '%d'\n", i, strcmp(result[i], *expected));
		printf("result[%d] is '%s' and *expected is '%s'\n", i, result[i], *expected);
        free(result[i]);
        i++;
        expected++;
         }
        free(result);
		}*/
	/*
{
	char	**str_array;
    char 	str[] = "split  ||this|for|me|||||!|";
	char	c = '|';

	str_array = ft_split(str, c);
	printf("'%s' split by '%c' results in:\n", str, c);
		printf("'%s' '%s' '%s' '%s' '%s' '%s' \n", str_array[0], str_array[1],
		str_array[2], str_array[3], str_array[4], str_array[5]);
	free(str_array[0]);
	free(str_array[1]);
	free(str_array[2]);
	free(str_array[3]);
	free(str_array[4]);
	free(str_array[5]);
	free(str_array);
}*/
/*
//	char	str[] = ",,,So long,,, and thanks,,, for all, the fish,,,";
//	char    str[] = "   So-long    and-thanks    for-all    the-fish    ";
//	char	c = ',';
	char str[] = "      split       this for   me  !       ";
	char    c = ' ';
*//*
	char	str2[] = "\0aa\0bbb";
	char	c = '\0';
	str_array = ft_split(str2, c); 
	
	printf("'%s' split by '%c' results in:\n", str2, c);
	printf("str_array[0] = '%s' and str_array[1] = '%s' \n", str_array[0], str_array[1]);
}
*/

