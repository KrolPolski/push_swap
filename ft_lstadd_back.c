/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rboudwin <rboudwin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 14:41:30 by rboudwin          #+#    #+#             */
/*   Updated: 2023/11/06 17:01:51 by rboudwin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*back;

	if (new == NULL)
		return ;
	if (lst == NULL)
	{
		lst = &new;
		return ;
	}
	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	back = ft_lstlast(*lst);
	if (back == NULL)
		return ;
	back->next = new;
}
/*
#include <stdio.h>

int	main(void)
{
	t_list **lst;
	char	str[] = "fish";
	char	str1[] = "duck";
	char	str2[] = "pond";
	t_list *curr;

	lst = malloc(sizeof(t_list) * 4);
	*lst = ft_lstnew(str);
	ft_lstadd_back(lst, ft_lstnew(str1));
	ft_lstadd_back(lst, ft_lstnew(str2));
	curr = *lst;
	printf("The three list items are as follows: \n");
   	printf("'%s'", curr->content);
	curr = curr->next;
   	printf("'%s'", curr->content);
   	curr = curr->next;
	printf("'%s'", curr->content);
	free(lst);
}*/
