/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rboudwin <rboudwin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 14:23:25 by rboudwin          #+#    #+#             */
/*   Updated: 2023/10/29 17:53:25 by rboudwin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
    char    *tmp_str;
	int		i;
	int		length;

 	i = 0;
	length = ft_strlen(s);
    tmp_str = malloc(length + 1);
	if (tmp_str == NULL)
		return (NULL);
    while (s[i] != '\0')
{
	tmp_str[i] = f(s[i]);
	i++;
}
	tmp_str[i] = '\0';
	return (tmp_str);

}

int main(void)
{
    char const *s[] = "so long and thanks for all the fish";

    ft_strmapi(s, ft_toupper(10, 'l'));

}
