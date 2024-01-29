/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   choose_push_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rboudwin <rboudwin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 10:44:25 by rboudwin          #+#    #+#             */
/*   Updated: 2024/01/29 10:56:48 by rboudwin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	initialize_ccp(t_vec *a, t_vec *b, t_ccp *z)
{
	z->i = 0;
	z->k = 0;
	z->index_a = a->len;
	z->index_b = b->len;
	z->min_total_cost = a->len + b->len;
	z->min_a_cost = a->len + b->len;
	z->b_max = find_max(b);
	z->b_min = find_min(b, z->b_max);
	z->b_max_index = vec_int_to_index(b, z->b_max);
	z->b_min_index = vec_int_to_index(b, z->b_min);
}

void	resolve_min_cost(t_ccp *z, int insertion)
{
	if (z->total_cost < z->min_total_cost)
	{
		z->min_total_cost = z->total_cost;
		z->index_a = z->i;
		if (!insertion)
			z->index_b = z->b_max_index;
		else
			z->index_b = z->k;
	}
}

void	calculate_costs(t_ccp *z, int insertion)
{
	if (z->same_direction == 1)
	{
		if (z->a_cost > z->b_cost)
			z->total_cost = z->a_cost;
		else
			z->total_cost = z->b_cost;
	}
	else
	{
		if (z->a_cost_forward <= z->a_cost_reverse)
			z->a_cost = z->a_cost_forward;
		else
			z->a_cost = z->a_cost_reverse;
		if (z->b_cost_forward <= z->b_cost_reverse)
			z->b_cost = z->b_cost_forward;
		else
			z->b_cost = z->b_cost_reverse;
		z->total_cost = z->a_cost + z->b_cost;
	}
	resolve_min_cost(z, insertion);
}
