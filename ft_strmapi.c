/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rboudwin <rboudwin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 14:23:25 by rboudwin          #+#    #+#             */
/*   Updated: 2023/10/27 14:44:00 by rboudwin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
    char    *tmp_str;

    tmp_str = malloc(ft_strlen(s) + 1);
    return (tmp_str);

}

int main(void)
{
    char const *s[] = "so long and thanks for all the fish";

    ft_strmapi(s, ft_toupper(10, 'l'));

}
