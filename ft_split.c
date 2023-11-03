/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rboudwin <rboudwin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 15:48:23 by rboudwin          #+#    #+#             */
/*   Updated: 2023/11/03 10:51:02 by rboudwin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

struct s_counter
{
	int	i;
	int	j;
	int	k;
};

static char	**ft_initial_mallocs(char const *s)
{
	char	**str_array;

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
	return (str_array);
}

char	**ft_split_cleanup(char **str_array, struct s_counter ctr)
{
	str_array[ctr.j][ctr.k] = '\0';
	if (ctr.j == 0)
		ctr.j++;
	str_array[ctr.j] = NULL;
	return (str_array);
}

char	**ft_split_main_logic(char const *s, char **str_array,
		struct s_counter ctr, char c)
{
	while (s[ctr.i] == c && s[ctr.i] != '\0')
		ctr.i++;
	while (s[ctr.i] != '\0')
	{
		if (s[ctr.i] != c)
			str_array[ctr.j][ctr.k++] = s[ctr.i];
		else if (s[ctr.i] == c && s[ctr.i + 1] != c && ctr.k != 0)
		{
			str_array[ctr.j][ctr.k] = '\0';
			ctr.k = 0;
			str_array[++ctr.j] = malloc(ft_strlen(s) + 1);
			if (str_array[ctr.j] == NULL)
			{
				while (ctr.k < ctr.j)
					free(str_array[ctr.k++]);
				free(str_array);
				return (NULL);
			}
		}
		ctr.i++;
	}
	return (ft_split_cleanup(str_array, ctr));
}

char	**ft_split(char const *s, char c)
{
	struct s_counter	ctr;
	char				**str_array;

	str_array = ft_initial_mallocs(s);
	if (str_array == NULL)
		return (NULL);
	if (c == '\0')
	{
		ft_strlcpy(str_array[0], s, ft_strlen(s));
		str_array[1] = NULL;
		return (str_array);
	}
	ctr.i = 0;
	ctr.j = 0;
	ctr.k = 0;
	ft_split_main_logic(s, str_array, ctr, c);
	return (str_array);
}
/*
#include <stdio.h>
#include <string.h>

int	main(void)
{
	char	str[] = "                 ";
    char	c = ' ';
	char	**result;

	result = ft_split(str, c);
	printf("For the string '%s' and c of '%c', results are: \n", str, c);
	printf("'%s' '%s'", result[0], result[1]);
*/
/*
char    **expected = (char*[6]){"split  ", "this", "for", "me", "!", NULL};

    char    *s = "split  ||this|for|me|||||!|";
	int             i = 0;
	char    **result = ft_split(s, '|');
    while (result[i]) {
		printf("strcmp(result[%d], *expected) is '%d'\n",
	   	i, strcmp(result[i], *expected));
		printf("result[%d] is '%s' and *expected is '%s'\n",
	   	i, result[i], *expected);
        free(result[i]);
        i++;
        expected++;
         }
        free(result);
		}
*/	
/*
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
}

//	char	str[] = ",,,So long,,, and thanks,,, for all, the fish,,,";
//	char    str[] = "   So-long    and-thanks    for-all    the-fish    ";
//	char	c = ',';
	char str[] = "      split       this for   me  !       ";
	char    c = ' ';
*//*
	char	str2[] = "\0aa\0bbb";
	char	c = '\0';
	char 	**str_array;
	str_array = ft_split(str2, c); 
	
	printf("'%s' split by '%c' results in:\n", str2, c);
	printf("str_array[0] = '%s' and str_array[1] = '%s' \n", 
	str_array[0], str_array[1]);*/
}
