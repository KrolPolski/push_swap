/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rboudwin <rboudwin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 11:47:06 by rboudwin          #+#    #+#             */
/*   Updated: 2024/01/15 11:48:04 by rboudwin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
int	print_vector(t_vec *vec)
{
	size_t	i;

	i = 0;
	while (i < vec->len)
	{
		ft_printf("%d, ", *(int *)(vec_get(vec, i)));
		i++;
	}
	ft_printf("\n");
	return (1);
}

int	check_order(t_vec *a)
{
	int	i;
	int	in_order;

	i = 1;
	in_order = 1;
	while (i < a->len)
	{
		if (*(int *)(vec_get(a, i - 1)) > *(int *)(vec_get(a, i)))
			in_order = 0;
		i++;
	}
	return (in_order);
}

int	vec_int(t_vec *a, int index)
{
	int	*ptr;
	int	x;

	ptr = vec_get(a, index);
	x = *ptr;
	return (x);
}

int	find_max(t_vec *a)
{
	int	index;
	int	max;

	index = 0;
	max = 0;
	while (index < a->len)
	{
		if (vec_int(a, index) > max)
			max = vec_int(a, index);
		index++;
	}
	return (max);
}
int	find_min(t_vec *a, int max)
{
	int	index;
	int	min;

	index = 0;
	min = max;
	while (index < a->len)
	{
		if (vec_int(a, index) < min)
			min = vec_int(a, index);
		index++;
	}
	return (min);
}
int	smart_rotate(t_vec *a, int target)
{
	//we want to rotate to get the target 
	//value on top, but we don't know which direction will be more efficient yet.
	//We can use the index, distance from 0 or distance from len - 1
	int from_zero;
	int from_end;
	int	i;

	i = 0;
	while (i < a->len && vec_int(a, i) != target)
	{
		i++;
	}
	ft_printf("i = %d", i);
	if (vec_int(a, i) == target)
	{
		from_zero = i;
		from_end = a->len - 1 - i;
	}
	if (from_zero <= from_end)
		while (i > 0)
		{
			ra(a, 1);
			i--;
		}
		//rotate using ra(a) i number of times
	else
		i = a->len - i;
		while (i > 0)
		{
			rra(a, 1);
			i--;
		}
		//rotate using rra(a) a->len - i number of times
}

/*We need to determine which item in stack a
 will cost the least in terms of rotates to find
  its correct position in stack b. This will return the 
  index of the cheapest one*/
//iterations:
//1. first choose cheapest one only considering a rotates
//2. consider b rotates
//3. consider double rotates
int	choose_cheapest_push(t_vec *a, t_vec *b)
{
	int	a_cost;
	int a_cost_forward;
	int a_cost_reverse;
	int	b_cost;
	int	min_a_cost;
	int	min_b_cost;
	int total_cost;
	int	min_total_cost;
	int	index;
	int	i;

	i = 0;
	index = a->len;
	min_a_cost = a->len;
	//we also need to think about whether to insist on next integer. probably not?
	//consider where to stop when we have only three left. i guess not here
	while (i < a->len)
	{
		if (vec_int(a, i) > vec_int(b, 0))
		{
			a_cost_forward = i;
			a_cost_reverse = a->len - i - 1;
			if (a_cost_forward <= a_cost_reverse)
				a_cost = a_cost_forward;
			else
				a_cost = a_cost_reverse;
			if (a_cost < min_a_cost)
			{
				ft_printf("We conclude that a_cost < min_a_cost and reset the minimum from %d to %d\n", min_a_cost, a_cost);
				min_a_cost = a_cost;
				index = i;
			}
		}
		i++;
		//by now we have figured out the cheapest simple push. need to check if rotating b can drop the cost further	
	}
	return (index);
}