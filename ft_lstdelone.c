/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rboudwin <rboudwin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 09:08:31 by rboudwin          #+#    #+#             */
/*   Updated: 2023/11/07 12:03:41 by rboudwin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (lst == NULL || del == NULL)
		return ;
	del(lst->content);
	free(lst);
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
	printf("After the last one was deleted\n");
	ft_lstdelone(curr, free);
	curr = lst;
	while (curr->next != NULL)
	{
		printf("'%s'\n", curr->content);
		curr = curr->next;
	}

}*/
