/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   choose_push_utils2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rboudwin <rboudwin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 10:56:54 by rboudwin          #+#    #+#             */
/*   Updated: 2024/01/30 14:27:11 by rboudwin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	choose_min_max(t_vec *a, t_vec *b, t_ccp *z)
{
	z->a_cost_forward = z->i;
	z->a_cost_reverse = a->len - z->i - 1;
	z->b_cost_forward = z->b_max_index;
	z->b_cost_reverse = b->len - z->b_max_index;
	if (z->a_cost_forward <= z->a_cost_reverse
		&& z->b_cost_forward <= z->b_cost_reverse)
	{
		z->a_cost = z->a_cost_forward;
		z->b_cost = z->b_cost_forward;
		z->same_direction = 1;
		calculate_costs(z, 0);
	}
	else if (z->a_cost_reverse <= z->a_cost_forward
		&& z->b_cost_reverse <= z->b_cost_forward)
	{
		z->a_cost = z->a_cost_reverse;
		z->b_cost = z->b_cost_reverse;
		z->same_direction = 1;
		calculate_costs(z, 0);
	}
	else
	{
		z->same_direction = 0;
		calculate_costs(z, 0);
	}
}

/* this allows our logic to wrap around the a vector
as needed, to avoid segfaults from going outside of index range*/
void	set_a_next(t_vec *a, t_ccp *z)
{
	if (z->i == a->len - 1)
		z->a_next = 0;
	else
		z->a_next = z->i + 1;
	if (z->i == 0)
		z->a_prev = a->len - 1;
	else
		z->a_prev = z->i - 1;
}

/* this allows our logic to wrap around the b vector
as needed, to avoid segfaults from going outside of index range*/
void	set_b_next(t_vec *b, t_ccp *z)
{
	if (z->k == 0)
		z->next = b->len - 1;
	else
		z->next = z->k - 1;
}
