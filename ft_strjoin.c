/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rboudwin <rboudwin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 11:02:05 by rboudwin          #+#    #+#             */
/*   Updated: 2023/10/31 10:45:22 by rboudwin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		s1_length;
	int		s2_length;
	char	*new_string;
//	int		tmp_len;

	s1_length = ft_strlen(s1);
	s2_length = ft_strlen(s2);
	new_string = malloc(s1_length + s2_length + 1);
	if (new_string == NULL)
		return (NULL);
	/*tmp_len =*/ ft_strlcpy(new_string, s1, s1_length + 1);
	/*tmp_len =*/ ft_strlcat(new_string, s2, s1_length + s2_length);
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
