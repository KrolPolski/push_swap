/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rboudwin <rboudwin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 12:11:21 by rboudwin          #+#    #+#             */
/*   Updated: 2023/11/07 14:25:31 by rboudwin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*curr_new;
	t_list	*new_list;
	t_list	*curr;

	if (lst == NULL || f == NULL)
		return (NULL);
	curr = lst;
	new_list = malloc(sizeof(t_list));
	if (!new_list)
		return (NULL);
	curr_new = new_list;
	while (curr != NULL)
	{
		ft_memmove(curr_new, curr, sizeof(t_list));
		f(curr_new->content);
		curr = curr->next;
		curr_new->next = malloc(sizeof(t_list));
		if (!curr_new->next)
		{
			ft_lstclear(&new_list, del);
			return (NULL);
		}
		curr_new = curr_new->next;
	}
	curr_new->next = NULL;
	return (new_list);
}
/*
static void *ft_adddollar(void *ptr)
{
	char *str;

	str = (char *)ptr;
	str[0] = '$';
	return (str);
}

#include <stdio.h>

int	main(void)
{
	t_list *lst;
	t_list *curr;
	t_list *new_list;


	lst = ft_lstnew(ft_strdup("one"));
	ft_lstadd_back(&lst, ft_lstnew(ft_strdup("two")));
	ft_lstadd_back(&lst, ft_lstnew(ft_strdup("three")));

	curr = lst;
	printf("Before:\n");
	while (curr->next != NULL)
	{
		printf("'%s'\n", curr->content);
		curr = curr->next;
	}
	printf("'%s'\n", curr->content);
	new_list = ft_lstmap(lst, ft_adddollar, free);
	printf("After the list was processed\n");
	curr = new_list;
	while (curr->next != NULL)
	{
		printf("'%s'\n", curr->content);
		curr = curr->next;
	}
}*/
