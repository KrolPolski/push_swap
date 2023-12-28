/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rboudwin <rboudwin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 10:20:29 by rboudwin          #+#    #+#             */
/*   Updated: 2023/11/01 15:34:42 by rboudwin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	int		length;
	char	*s2;

	length = ft_strlen(s1);
	s2 = malloc(length + 1);
	if (s2 == NULL)
		return (NULL);
	ft_strlcpy(s2, s1, length + 1);
	return (s2);
}
/*
#include <stdio.h>
int	main(void)
{
	char src[] = "Fish";
	char *dst;

	dst = ft_strdup(src);
	printf("The src was '%s' and the dst is now also '%s'", src, dst);
	free(dst);
}*/
