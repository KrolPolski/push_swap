/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rboudwin <rboudwin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 12:11:21 by rboudwin          #+#    #+#             */
/*   Updated: 2023/12/14 12:36:38 by rboudwin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*head;
	void	*fcont;

	head = NULL;
	while (lst)
	{
		fcont = f(lst->content);
		new = ft_lstnew(fcont);
		if (new == NULL)
		{
			ft_lstclear(&head, del);
			del(fcont);
		}
		ft_lstadd_back(&head, new);
		lst = lst->next;
	}
	return (head);
}
