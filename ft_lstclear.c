/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rboudwin <rboudwin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 09:21:49 by rboudwin          #+#    #+#             */
/*   Updated: 2023/11/07 11:44:23 by rboudwin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*curr;
	t_list	*next;

	curr = *lst;
	if (lst == NULL || *lst == NULL || del == NULL)
		return ;
	while (curr != NULL)
	{
		next = curr->next;
		if (curr->content != NULL)
			del(curr->content);
		del(curr);
		curr = next;
	}
	*lst = NULL;
}

/*
#include <stdio.h>

int	main(void)
{
	t_list *lst;
	t_list *curr;


	lst = ft_lstnew(ft_strdup("One"));
	ft_lstadd_back(&lst, ft_lstnew(ft_strdup("Two")));
	ft_lstadd_back(&lst, ft_lstnew(ft_strdup("Three")));

	curr = lst;
	printf("Before:\n");
	while (curr->next != NULL)
	{
		printf("'%s'\n", curr->content);
		curr = curr->next;
	}
	printf("'%s'\n", curr->content);
	printf("After the last two were deleted\n");
	curr = lst;
	ft_lstclear(&curr->next, free);
	while (curr != NULL)
	{
		printf("'%s'\n", curr->content);
		curr = curr->next;
	}

}*/
