/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   choose_push.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rboudwin <rboudwin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 16:22:19 by rboudwin          #+#    #+#             */
/*   Updated: 2024/01/26 11:32:40 by rboudwin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
/*We need to determine which item in stack a
 will cost the least in terms of rotates to find
  its correct position in stack b. This will return the 
  index of the cheapest one*/
//iterations:
//1. first choose cheapest one only considering a rotates
//2. consider b rotates
//3. consider double rotates
//Right now we are only considering costs as a + b rotates, 
//when we need to consider the impact on cost of double rotates.
//This might be the last optimization we need.
//also should consider costs of max and min insertions. 
//those two will get us over the finish line
//We should implement a cost discount for double push opportunities.
// maybe multiply by 0.5 if we could do a second push without any rotations
//but how do we implement that?
//need to check if the index after the one we are 
//working with is greater than the current index,
//but also less than the one on the bottom?

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

int	choose_cheapest_push(t_vec *a, t_vec *b)
{
	t_ccp	z;
	int		same_direction;

	initialize_ccp(a, b, &z);
	while (z.i < a->len)
	{
		if (z.i == a->len - 1)
			z.a_next = 0;
		else
			z.a_next = z.i + 1;
		if (z.i == 0)
			z.a_prev = a->len - 1;
		else
			z.a_prev = z.i - 1;
		while (z.k < b->len)
		{
			if (z.k == 0)
				z.next = b->len - 1;
			else
				z.next = z.k - 1;
			if (vec_int(a, z.i) < z.b_min)
			{
				z.a_cost_forward = z.i;
				z.a_cost_reverse = a->len - z.i - 1;
				z.b_cost_forward = z.b_max_index;
				z.b_cost_reverse = b->len - z.b_max_index;
				if (z.a_cost_forward <= z.a_cost_reverse
					&& z.b_cost_forward <= z.b_cost_reverse)
				{
					z.a_cost = z.a_cost_forward;
					z.b_cost = z.b_cost_forward;
					if (z.a_cost > z.b_cost)
						z.total_cost = z.a_cost;
					else
						z.total_cost = z.b_cost;
				}
				else if (z.a_cost_reverse <= z.a_cost_forward
					&& z.b_cost_reverse <= z.b_cost_forward)
				{
					z.a_cost = z.a_cost_reverse;
					z.b_cost = z.b_cost_reverse;
					if (z.a_cost > z.b_cost)
						z.total_cost = z.a_cost;
					else
						z.total_cost = z.b_cost;
				}
				else
				{
					if (z.a_cost_forward <= z.a_cost_reverse)
						z.a_cost = z.a_cost_forward;
					else
						z.a_cost = z.a_cost_reverse;
					if (z.b_cost_forward <= z.b_cost_reverse)
						z.b_cost = z.b_cost_forward;
					else
						z.b_cost = z.b_cost_reverse;
					z.total_cost = z.a_cost + z.b_cost;
				}
				if (z.total_cost < z.min_total_cost)
				{
					z.min_total_cost = z.total_cost;
					z.index_a = z.i;
					z.index_b = z.b_max_index;
				}
			}
			else if (vec_int(a, z.i) > z.b_max)
			{
				z.a_cost_forward = z.i;
				z.a_cost_reverse = a->len - z.i - 1;
				z.b_cost_forward = z.b_max_index;
				z.b_cost_reverse = b->len - z.b_max_index;
				if (z.a_cost_forward <= z.a_cost_reverse
					&& z.b_cost_forward <= z.b_cost_reverse)
				{
					z.a_cost = z.a_cost_forward;
					z.b_cost = z.b_cost_forward;
					if (z.a_cost > z.b_cost)
						z.total_cost = z.a_cost;
					else
						z.total_cost = z.b_cost;
				}
				else if (z.a_cost_reverse <= z.a_cost_forward
					&& z.b_cost_reverse <= z.b_cost_forward)
				{
					z.a_cost = z.a_cost_reverse;
					z.b_cost = z.b_cost_reverse;
					if (z.a_cost > z.b_cost)
						z.total_cost = z.a_cost;
					else
						z.total_cost = z.b_cost;
				}
				else
				{
					if (z.a_cost_forward <= z.a_cost_reverse)
						z.a_cost = z.a_cost_forward;
					else
						z.a_cost = z.a_cost_reverse;
					if (z.b_cost_forward <= z.b_cost_reverse)
						z.b_cost = z.b_cost_forward;
					else
						z.b_cost = z.b_cost_reverse;
					z.total_cost = z.a_cost + z.b_cost;
				}
				if (z.total_cost < z.min_total_cost)
				{
					z.min_total_cost = z.total_cost;
					z.index_a = z.i;
					z.index_b = z.b_max_index;
				}
			}
			else if (vec_int(a, z.i) > vec_int(b, z.k)
				&& vec_int(a, z.i) < vec_int (b, z.next))
			{
				z.a_cost_forward = z.i;
				z.b_cost_forward = z.k;
				z.a_cost_reverse = a->len - z.i - 1;
				z.b_cost_reverse = b->len - z.k - 1;
				if (z.a_cost_forward <= z.a_cost_reverse
					&& z.b_cost_forward <= z.b_cost_reverse)
				{
					z.a_cost = z.a_cost_forward;
					z.b_cost = z.b_cost_forward;
					same_direction = 1;
					if (z.a_cost > z.b_cost)
						z.total_cost = z.a_cost;
					else
						z.total_cost = z.b_cost;
					if (vec_int(a, z.a_next) > vec_int(a, z.i)
						&& vec_int(a, z.a_next) < vec_int (b, b->len - 1))
						z.total_cost--;
				}
				else if (z.a_cost_reverse <= z.a_cost_forward
					&& z.b_cost_reverse <= z.b_cost_forward)
				{
					z.a_cost = z.a_cost_reverse;
					z.b_cost = z.b_cost_reverse;
					same_direction = 1;
					if (z.a_cost > z.b_cost)
						z.total_cost = z.a_cost;
					else
						z.total_cost = z.b_cost;
					if (vec_int(a, z.a_next) > vec_int(a, z.i)
						&& vec_int(a, z.a_next) < vec_int (b, b->len - 1))
						z.total_cost--;
				}
				else
				{
					same_direction = 0;
					if (z.a_cost_forward <= z.a_cost_reverse)
						z.a_cost = z.a_cost_forward;
					else
						z.a_cost = z.a_cost_reverse;
					if (z.b_cost_forward <= z.b_cost_reverse)
						z.b_cost = z.b_cost_forward;
					else
						z.b_cost = z.b_cost_reverse;
					z.total_cost = z.a_cost + z.b_cost;
				}
				if (vec_int(a, z.a_next) > vec_int(a, z.i)
					&& vec_int(a, z.a_next) < vec_int (b, b->len - 1))
					z.total_cost--;
				if (z.total_cost < z.min_total_cost)
				{
					z.min_total_cost = z.total_cost;
					z.index_a = z.i;
					z.index_b = z.k;
				}
			}
			z.k++;
		}
		z.k = 0;
		z.i++;
	}
	if (z.index_a >= a->len || z.index_b >= b->len)
	{
		ft_printf("Invalid index selected by choose_cheapest_push\n");
		exit(EXIT_FAILURE);
	}
	execute_cheapest_push(a, b, z.index_a, z.index_b);
	return (1);
}

void	execute_cheapest_push(t_vec *a, t_vec *b, int index_a, int index_b)
{
	smart_rotate(a, b, vec_int(a, index_a), vec_int(b, index_b));
	pb(a, b, 1);
}

int	batch_push(t_vec *a, t_vec *b)
{
	smart_rotate(a, b, find_max(a), find_max(b));
	while (b->len > 0)
	{
		if (vec_int(b, 0) < vec_int(a, 0)
			&& vec_int(b, 0) > vec_int(a, a->len - 1))
			pa(a, b, 1);
		else if (vec_int(b, 0) > vec_int(a, 0)
			&& vec_int(b, 0) > vec_int(a, a->len -1))
		{
			pa(a, b, 1);
			sa(a, 1);
		}
		else if (vec_int(b, 0) > find_max(a) ||
			vec_int(b, 0) < find_min(a, find_max(a)))
		{
			smart_rotate_a(a, find_min(a, find_max(a)));
			pa(a, b, 1);
			if (vec_int(a, 0) == find_max(a))
				sa(a, 1);
		}
		else
			rra(a, 1);
	}
	return (1);
}
