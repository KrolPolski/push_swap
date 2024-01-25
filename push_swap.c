/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rboudwin <rboudwin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 15:17:15 by rboudwin          #+#    #+#             */
/*   Updated: 2024/01/25 11:18:09 by rboudwin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Parse the arguments and add them as elements to the vector */
void	reverse_sort_three(t_vec *b)
{
	if (vec_int(b, 0) > vec_int(b, 1) && vec_int(b, 2) > vec_int(b, 0))
		rrb(b, 1);
	else if (vec_int(b, 0) < vec_int(b, 1) && vec_int(b, 2) < vec_int(b, 0))
	{
		sb(b, 1);
	}
	else if (vec_int(b, 1) < vec_int(b, 2) && vec_int(b, 0) > vec_int(b, 2))
	{
		rrb(b, 1);
		sb(b, 1);
	}
	else if (vec_int(b, 0) > vec_int(b, 1) && vec_int(b, 1) > vec_int(b, 2))
		return ;
	else if (vec_int(b, 0) < vec_int(b, 1) && vec_int(b, 1) < vec_int(b, 2))
	{
		rb(b, 1);
		sb(b, 1);
	}
	else if (vec_int(b, 0) < vec_int(b, 2) && vec_int(b, 2) < vec_int(b, 1))
		rb(b, 1);
}

void	push_swap_three(t_vec *a)
{
	if (vec_int(a, 0) < vec_int(a, 1) && vec_int(a, 1) < vec_int(a, 2))
		return ;
	if (vec_int(a, 0) > vec_int(a, 1) && vec_int(a, 2) > vec_int(a, 0))
	{
		sa(a, 1);
		return ;
	}
	else if (vec_int(a, 0) < vec_int(a, 1) && vec_int(a, 2) < vec_int(a, 0))
	{
		rra(a, 1);
		return ;
	}
	else if (vec_int(a, 1) < vec_int(a, 2) && vec_int(a, 0) > vec_int(a, 2))
	{
		ra(a, 1);
		return ;
	}
	else if (vec_int(a, 0) > vec_int(a, 1) && vec_int(a, 1) > vec_int(a, 2))
	{
		sa(a, 1);
		rra(a, 1);
		return ;
	}
	else if (vec_int(a, 0) > vec_int(a, 1) && vec_int(a, 2) > vec_int(a, 0))
	{
		sa(a, 1);
		ra(a, 1);
		return ;
	}
	else if (vec_int(a, 0) < vec_int(a, 1) && vec_int(a, 2) > vec_int(a, 0))
	{
		rra(a, 1);
		sa(a, 1);
	}
}

//we need to handle 2, or 3 numbers.
int	push_swap_small(t_vec *a)
{
	int	i;

	i = 0;
	if (a->len == 2)
	{
		if (*(int *)vec_get(a, 0) > *(int *)vec_get(a, 1))
		{
			sa(a, 1);
			return (1);
		}
		else
			return (1);
	}
	else
		push_swap_three(a);
	return (1);
}

int	push_swap_five(t_vec *a, t_vec *b)
{
	pb(a, b, 1);
	pb(a, b, 1);
	push_swap_small(a);
	if (vec_int(b, b->len - 1) > vec_int(b, 0))
		sb(b, 1);
	if (vec_int(b, 0) < vec_int(a, 0))
	{
		pa(a, b, 1);
		pa(a, b, 1);
		return (1);
	}
	while (vec_int(b, 0) < vec_int(a, a->len - 1))
		rra(a, 1);
	pa(a, b, 1);
	while (vec_int(b, 0) < vec_int(a, a->len - 1)
		&& vec_int(a, 0) > vec_int(a, a->len - 1))
		rra(a, 1);
	pa(a, b, 1);
	while (vec_int(a, 0) > vec_int(a, a->len - 1))
		rra(a, 1);
	return (1);
}

/*push three to b, sort three, 
choose cheapest to push to b,
push to b, loop until there are only three left in a.
Then push them all back to a in an intelligent way*/
int	push_swap_medium(t_vec *a, t_vec *b)
{
	pb(a, b, 1);
	pb(a, b, 1);
	pb(a, b, 1);
	reverse_sort_three(b);
	while (a->len > 3)
		choose_cheapest_push(a, b);
	push_swap_three(a);
	batch_push(a, b);
	smart_rotate_a(a, find_min(a, find_max(a)));
	return (1);
}

int	push_swap(t_vec *a, t_vec *b)
{
	if (a->len == 1)
		return (1);
	else if (a->len < 4)
		push_swap_small(a);
	else if (a->len < 6)
		push_swap_five(a, b);
	else
		push_swap_medium(a, b);
	return (1);
}
