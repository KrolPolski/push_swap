/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rboudwin <rboudwin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 09:33:17 by rboudwin          #+#    #+#             */
/*   Updated: 2024/01/16 10:49:12 by rboudwin         ###   ########.fr       */
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
//this is using ra functions etc even when it is the b vector. we need
//to figure out whether to  use ra or rb functions instead.
int	smart_rotate_a(t_vec *a, int target)
{
	//we want to rotate to get the target 
	//value on top, but we don't know which direction will be more efficient yet.
	//We can use the index, distance from 0 or distance from len - 1
	int from_zero;
	int from_end;
	int	i;

//	ft_printf("we entered smart_rotate\n");
	i = 0;
	while (i < a->len && vec_int(a, i) != target)
	{
		i++;
	}
	//ft_printf("i = %d\n", i);
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
	return (1);
}
int	smart_rotate_b(t_vec *b, int target)
{
	//we want to rotate to get the target 
	//value on top, but we don't know which direction will be more efficient yet.
	//We can use the index, distance from 0 or distance from len - 1
	int from_zero;
	int from_end;
	int	i;

//	ft_printf("we entered smart_rotate\n");
	i = 0;
	while (i < b->len && vec_int(b, i) != target)
	{
		i++;
	}
	//ft_printf("i = %d\n", i);
	if (vec_int(b, i) == target)
	{
		from_zero = i;
		from_end = b->len - 1 - i;
	}
	if (from_zero <= from_end)
		while (i > 0)
		{
			rb(b, 1);
			i--;
		}
		//rotate using ra(a) i number of times
	else
		i = b->len - i;
		while (i > 0)
		{
			rrb(b, 1);
			i--;
		}
		//rotate using rra(a) a->len - i number of times
	return (1);
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
	int	index_a;
	int	index_b;
	int	i;
	int	k;
	int next;

	i = 0;
	k = 0;
	index_a = a->len;
	index_b = b->len;
	min_a_cost = a->len;
	//we also need to think about whether to insist on next integer. probably not?
	//consider where to stop when we have only three left. i guess not here
	while (i < a->len)
	{
		while (k < b->len)
		{
			if (k == 0)
				next = b->len - 1;
			else
				next = k - 1;
			//this line triggers a seg fault because k can be 0 in some cases.
			if (vec_int(a, i) > vec_int(b, k) && vec_int(a, i) < vec_int (b, next))
			{
				a_cost_forward = i + k;
				a_cost_reverse = a->len - i - 1 + k;
				if (a_cost_forward <= a_cost_reverse)
					a_cost = a_cost_forward;
				else
					a_cost = a_cost_reverse;
				if (a_cost < min_a_cost)
				{
				//	ft_printf("We conclude that a_cost < min_a_cost and reset the minimum from %d to %d\n", min_a_cost, a_cost);
					min_a_cost = a_cost;
					index_a = i;
					index_b = k;
				}
			}
			k++;
		}
		k = 0;
		i++;
		
		//by now we have figured out the cheapest simple push. need to check if rotating b can drop the cost further	
	}
//	ft_printf("We have concluded that the cheapest push will be from index_a %d (%d)to index_b %d (%d)\n", index_a, vec_int(a, index_a), index_b, vec_int(b, index_b));
	execute_cheapest_push(a, b, index_a, index_b);
	return (1);
}
int	execute_cheapest_push(t_vec *a, t_vec *b, int index_a, int index_b)
{
	//ft_printf("a_index: %d b_index: %d\n", index_a, index_b);
	//need to add logic to double rotate when possible, for now not worrying about it
	smart_rotate_a(a, vec_int(a, index_a));
	smart_rotate_b(b, vec_int(b, index_b));
	pb(a, b, 1);
	return (1);
}
int	batch_push(t_vec *a, t_vec *b)
{
	
	smart_rotate_b(b, find_max(b));
	smart_rotate_a(a, find_max(a));
	//print_vector(a);
	//print_vector(b);
	while (b->len > 0)
	{
		if (vec_int(b, 0) < vec_int(a, 0) &&
			vec_int(b, 0) > vec_int(a, a->len - 1))
			pa(a, b, 1);
		else if (vec_int(b, 0) > vec_int(a, 0) &&
			vec_int(b, 0) > vec_int(a, a->len -1))
		{
			pa(a, b, 1);
			sa(a, 1);
		}
		else
			rra(a, 1);
	}
	return (1);
}
