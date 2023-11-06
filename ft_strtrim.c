/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rboudwin <rboudwin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 14:01:00 by rboudwin          #+#    #+#             */
/*   Updated: 2023/11/06 11:20:24 by rboudwin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_trim_handler(char const *s1, char const *set, int i, int j)
{
	int		k;
	char	*clean_string;

	while (s1[i] != '\0' && ft_strchr(set, s1[i]) != NULL)
		i++;
	while (j > 0 && ft_strchr(set, s1[j]) != NULL)
		j--;
	if (j < i)
	{
		clean_string = malloc(1);
		if (clean_string == NULL)
			return (NULL);
		clean_string[0] = '\0';
		return (clean_string);
	}
	clean_string = malloc(j - i + 2);
	if (clean_string == NULL)
		return (NULL);
	k = 0;
	while (i <= j)
		clean_string[k++] = s1[i++];
	clean_string[k] = '\0';
	return (clean_string);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		j;
	char	*clean_string;

	i = 0;
	if (s1 == NULL)
		return (NULL);
	j = ft_strlen(s1) - 1;
	if (s1[0] == '\0')
	{
		clean_string = malloc(1);
		if (clean_string == NULL)
			return (NULL);
		else
		{
			clean_string[0] = '\0';
			return (clean_string);
		}
	}
	if (set[0] == '\0')
		return (ft_strdup(s1));
	clean_string = ft_trim_handler(s1, set, i, j);
	return (clean_string);
}
/*
#include <stdio.h>

int	main(void)
{
	char	dirty_string[] = "=!===!==Da!ta!=====";
	char	set[] = "=!";
	char	*clean_string;

	clean_string = ft_strtrim(dirty_string, set);
	printf("'%s' with '%s' removed is '%s'", dirty_string, set, clean_string);
	free(clean_string);
}*/
