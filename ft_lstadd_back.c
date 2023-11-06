/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rboudwin <rboudwin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 14:41:30 by rboudwin          #+#    #+#             */
/*   Updated: 2023/11/06 15:32:53 by rboudwin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list *back;
	
	if (new == NULL)
		return;
	if (lst == NULL)
	{
		lst = &new;
		return;
	}
	if (*lst == NULL)
		*lst = new;
	back = ft_lstlast(*lst);
	if (back == NULL)
		return;
	back->next = new;
	back = back->next;
	back->next = NULL;
}
