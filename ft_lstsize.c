/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rboudwin <rboudwin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 14:28:05 by rboudwin          #+#    #+#             */
/*   Updated: 2023/11/06 17:03:39 by rboudwin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int		i;
	t_list	*curr;

	i = 1;
	if (lst == NULL)
		return (0);
	curr = lst;
	while (curr->next != NULL)
	{
		i++;
		curr = curr->next;
	}
	return (i);
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
	printf("There should now be two items in the list: '%d'\n", ft_lstsize(first));
}*/
