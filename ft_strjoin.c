/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rboudwin <rboudwin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 11:02:05 by rboudwin          #+#    #+#             */
/*   Updated: 2023/11/01 11:03:08 by rboudwin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned char	*ft_strjoin(unsigned char const *s1, unsigned char const *s2)
{
	int				s1_length;
	int				s2_length;
	unsigned char	*new_string;

	s1_length = ft_strlen(s1);
	s2_length = ft_strlen(s2);
	new_string = malloc(s1_length + s2_length + 1);
	if (new_string == NULL)
		return (NULL);
	ft_strlcpy(new_string, s1, s1_length + 1);
	ft_strlcat(new_string, s2, s1_length + s2_length + 1);
	return (new_string);
}

/*
#include <stdio.h>

int	main(void)
{
	char s1[] = "So long";
	char s2[] = " and thanks for all the fish!";
	char *new_string;
	
	new_string = ft_strjoin(s1, s2);
	printf("'%s' + '%s' = '%s'\n", s1, s2, new_string);

}*/
