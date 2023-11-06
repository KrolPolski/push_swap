/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rboudwin <rboudwin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 14:28:05 by rboudwin          #+#    #+#             */
/*   Updated: 2023/11/06 14:34:38 by rboudwin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int ft_lstsize(t_list *lst)
{
	int i;
	t_list *curr;
	
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
