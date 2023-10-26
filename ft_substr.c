/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rboudwin <rboudwin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 10:45:05 by rboudwin          #+#    #+#             */
/*   Updated: 2023/10/26 10:56:59 by rboudwin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substring;
	int		i;
	size_t	j;

	i = start;
	j = 0;
	substring = malloc(len + 1);
	if (substring == NULL)
		return (NULL);
	while (s[i] != '\0' && j < len)
	{
		substring[j] = s[i];
		i++;
		j++;
	}
	substring[j] = '\0';
	return (substring);
}
/*
#include <stdio.h>

int	main(void)
{
	char string[] = "So long and thanks for all the fish!";
	char *substr;
	
	substr = ft_substr(string, 3, 4);
	printf("The string was '%s' and the substring is '%s'\n", string, substr);
	free(substr);
}*/
