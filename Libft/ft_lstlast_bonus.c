/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rboudwin <rboudwin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 14:37:00 by rboudwin          #+#    #+#             */
/*   Updated: 2023/11/06 17:02:55 by rboudwin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*curr;

	if (lst == NULL)
		return (NULL);
	curr = lst;
	while (curr->next != NULL)
	{
		curr = curr->next;
	}
	return (curr);
}
/*
#include <stdio.h>

int	main(void)
{
	t_list *first;
	t_list *new;
	t_list *last;
	char str[] = "Fish";
	char str2[] = "sticks";
	first = ft_lstnew(str);
	new = ft_lstnew(str2);
	printf("The front item of the list was: '%s'\n", first->content);
	ft_lstadd_front(&first, new);
	printf("The front item of the list is now: '%s'\n", first->content);
	last = ft_lstlast(first);
	printf("The last item of the list is now: '%s'\n", last->content);
}*/
