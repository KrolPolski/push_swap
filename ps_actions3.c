/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_actions3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rboudwin <rboudwin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 15:18:06 by rboudwin          #+#    #+#             */
/*   Updated: 2024/01/25 11:13:18 by rboudwin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*rrr : rra and rrb at the same time.*/
int	rrr(t_vec *a, t_vec *b, int print)
{
	if (rra(a, 0) == -1 || rrb(b, 0) == -1)
		return (-1);
	if (print)
		ft_printf("rrr\n");
	return (1);
}
