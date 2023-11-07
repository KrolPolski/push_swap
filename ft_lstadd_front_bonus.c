/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rboudwin <rboudwin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 14:19:44 by rboudwin          #+#    #+#             */
/*   Updated: 2023/11/06 17:02:40 by rboudwin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	new->next = *lst;
	*lst = new;
}
/*
#include <stdio.h>

int	main(void)
{
	t_list *first;
	t_list *new;
	char str[] = "Fish";
	char str2[] = "sticks";
	first = ft_lstnew(str);
	new = ft_lstnew(str2);
	printf("The front item of the list was: '%s'\n", first->content);
	ft_lstadd_front(&first, new);
	printf("The front item of the list is now: '%s'\n", first->content);
}*/
