/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rboudwin <rboudwin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 11:14:28 by rboudwin          #+#    #+#             */
/*   Updated: 2023/11/07 11:55:34 by rboudwin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void ft_lstiter(t_list *lst, void (*f)(void *))
{
	t_list *curr;
	
	if (lst == NULL || f == NULL)
		return ;
	curr = lst;
	while (curr != NULL)
	{
		f(curr->content);
		curr = curr->next;
	}
}
/*
static void ft_adddollar(void *ptr)
{
	char *str;
	
	str = (char *)ptr;	
	str[0] = '$';
}

#include <stdio.h>

int	main(void)
{
	t_list *lst;
	t_list *curr;


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
	printf("After the list was processed\n");
	curr = lst;
	ft_lstiter(lst, ft_adddollar);
	while (curr != NULL)
	{
		printf("'%s'\n", curr->content);
		curr = curr->next;
	}

}*/
