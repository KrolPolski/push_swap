/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rboudwin <rboudwin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 09:33:17 by rboudwin          #+#    #+#             */
/*   Updated: 2024/01/24 16:16:44 by rboudwin         ###   ########.fr       */
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
	size_t	i;
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
int	vec_int_to_index(t_vec *a, int x)
{
	size_t i;

	//ft_printf("We entered vec_int_to_index\n");
	i = 0;
	while (i < a->len)
	{
		if (vec_int(a, i) == x)
	{	//ft_printf("index of %d is %d\n", x, i);
			return i;
	}
	i++;
	} 
	return (-1);
}

int	find_max(t_vec *a)
{
	size_t	index;
	int	max;

	index = 0;
	max = -2147483648;
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
	size_t	index;
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
	size_t	i;

	from_zero = a->len;
	from_end = a->len;
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
	int from_zero;
	int from_end;
	size_t	i;
	from_zero = b->len;
	from_end = b->len;

	i = 0;
	while (i < b->len && vec_int(b, i) != target)
	{
		i++;
	}
	if (vec_int(b, i) == target)
	{
		from_zero = i;
		from_end = b->len - 1 - i;
	}
	if (from_zero <= from_end)
	{
		while (i > 0)
		{
			rb(b, 1);
			i--;
		}
	}
	else
		i = b->len - i;
	while (i > 0)
	{
		rrb(b, 1);
		i--;
	}
	return (1);
}
/*Rotates to two targets, taking advantage of double rotates where possible*/
int	smart_rotate(t_vec *a, t_vec *b, int a_target, int b_target)
{
	int		a_from_zero;
	int		a_from_end;
	int		b_from_zero;
	int		b_from_end;
	size_t	i;
	size_t	k;

	a_from_zero = a->len;
	a_from_end = a->len;
	b_from_zero = b->len;
	b_from_end = b->len;

//	ft_printf("we entered smart_rotate\n");
	i = 0;
	k = 0;
	while (i < a->len && vec_int(a, i) != a_target)
	{
		i++;
	}
	while (k < b->len && vec_int(b, k) != b_target)
	{
		k++;
	}
	//ft_printf("i = %d\n", i);
	if (vec_int(a, i) == a_target)
	{
		a_from_zero = i;
		a_from_end = a->len - 1 - i;
	}
	if (vec_int(b, k) == b_target)
	{
		b_from_zero = k;
		b_from_end = b->len - 1 - k;
	}
	if (a_from_zero <= a_from_end && b_from_zero <= b_from_end)
	{
		while (i > 0 && k > 0)
		{
			rr(a, b, 1);
			i--;
			k--;
		}
		/*while (i > 0)
		{
			ra(a, 1);
			i--;
		}
		while (k > 0)
		{
			rb(b, 1);
			k--;
		}*/
		//rotate using ra(a) i number of times
	}
	else if (a_from_zero > a_from_end && b_from_zero >= b_from_end)
	{
		while (i < a->len && k < b->len)
		{
			rrr(a, b, 1);
			i++;
			k++;
		}
		/*while (i > 0)
		{
			rra(a, 1);
			i--;
		}
		while (k > 0)
		{
			rrb(b, 1);
			k--;
		}*/
	}
		smart_rotate_a(a, a_target);
		smart_rotate_b(b, b_target);
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
//Right now we are only considering costs as a + b rotates, 
//when we need to consider the impact on cost of double rotates.
//This might be the last optimization we need.
//also should consider costs of max and min insertions. those two will get us over the finish line
//We should implement a cost discount for double push opportunities. maybe multiply by 0.5 if we could do a second push without any rotations
//but how do we implement that?
//need to check if the index after the one we are working with is greater than the current index,
//but also less than the one on the bottom?
int	choose_cheapest_push(t_vec *a, t_vec *b)
{
	t_ccp	z;
	int same_direction;
	z.i = 0;
	z.k = 0;
	z.index_a = a->len;
	z.index_b = b->len;
	z.min_total_cost = a->len + b->len;
	z.min_a_cost = a->len + b->len;
	z.b_max = find_max(b);
	z.b_min = find_min(b, z.b_max);
	//print_vector(b);
	//ft_printf("b_max is %d and b_min is %d\n", z.b_max, z.b_min);
	z.b_max_index = vec_int_to_index(b, z.b_max);
	z.b_min_index = vec_int_to_index(b, z.b_min);
	//we also need to think about whether to insist on next integer. probably not?
	//consider where to stop when we have only three left. i guess not here
	while (z.i < a->len)
	{
		if (z.i == a->len - 1)
		{
			z.a_next = 0;
		}
		else
			z.a_next = z.i + 1;
		if (z.i == 0)
		{
			z.a_prev = a->len - 1;
		}
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
				if (z.a_cost_forward <= z.a_cost_reverse && z.b_cost_forward <= z.b_cost_reverse)
				{
					z.a_cost = z.a_cost_forward;
					z.b_cost = z.b_cost_forward;
					if (z.a_cost > z.b_cost)
						z.total_cost = z.a_cost;
					else
						z.total_cost = z.b_cost;
				}
				else if (z.a_cost_reverse <= z.a_cost_forward && z.b_cost_reverse <= z.b_cost_forward)
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
					{z.min_total_cost = z.total_cost;
					z.index_a = z.i;
					z.index_b = z.b_max_index;}
			}
			else if (vec_int(a, z.i) > z.b_max)
			{
				z.a_cost_forward = z.i;
				z.a_cost_reverse = a->len - z.i - 1;
				z.b_cost_forward = z.b_max_index;
				z.b_cost_reverse = b->len - z.b_max_index;
				if (z.a_cost_forward <= z.a_cost_reverse && z.b_cost_forward <= z.b_cost_reverse)
				{
					z.a_cost = z.a_cost_forward;
					z.b_cost = z.b_cost_forward;
					if (z.a_cost > z.b_cost)
						z.total_cost = z.a_cost;
					else
						z.total_cost = z.b_cost;
				}
				else if (z.a_cost_reverse <= z.a_cost_forward && z.b_cost_reverse <= z.b_cost_forward)
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
					{z.min_total_cost = z.total_cost;
					z.index_a = z.i;
					z.index_b = z.b_max_index;}
			}
			else if (vec_int(a, z.i) > vec_int(b, z.k) && vec_int(a, z.i) < vec_int (b, z.next))
			{
				z.a_cost_forward = z.i;
				z.b_cost_forward = z.k;
				z.a_cost_reverse = a->len - z.i - 1;
				z.b_cost_reverse = b->len - z.k - 1;
				if (z.a_cost_forward <= z.a_cost_reverse && z.b_cost_forward <= z.b_cost_reverse)
				{
					z.a_cost = z.a_cost_forward;
					z.b_cost = z.b_cost_forward;
					same_direction = 1;
					if (z.a_cost > z.b_cost)
						z.total_cost = z.a_cost;
					else
						z.total_cost = z.b_cost;
				}
				else if (z.a_cost_reverse <= z.a_cost_forward && z.b_cost_reverse <= z.b_cost_forward)
				{
					z.a_cost = z.a_cost_reverse;
					z.b_cost = z.b_cost_reverse;
					same_direction = 1;
					if (z.a_cost > z.b_cost)
						z.total_cost = z.a_cost;
					else
						z.total_cost = z.b_cost;
				}
				else {
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
				//print_vector(a);
				//ft_printf("i is %d and a_next is %d\n", z.i, z.a_next);
				//print_vector(b);
				//ft_printf("k is %d and z.next is %d\n", z.k, z.next);
				//need to avoid a segfault for i going out of bounds
				//the approach below is flawed because this should only count the a cost savings, not total cost.
					if (vec_int(a, z.a_next) > vec_int(a, z.i) && vec_int(a, z.a_next) < vec_int (b, b->len - 1))
					//why do we care that a_cost is higher than b_cost?
					//
					{
							//this is making things worse in some cases.
							//0.75 worked better than 0.5. Why?
							if (z.a_cost >= 2 * z.b_cost)
								z.total_cost *= 0.75;
							else
								z.total_cost--;
						//if (!same_direction)
							//z.total_cost = z.a_cost * 0.5 + z.b_cost;
						//else
					//	if (z.total_cost > 10)
						//	z.total_cost--;
						
						//else if (z.a_cost > z.b_cost)
						//	z.total_cost -= (z.a_cost - z.b_cost) * 0.5; 
				/*	if (z.a_next == a->len - 1)
						z.a_2next = 0;
					else
						z.a_2next = z.a_next + 1;
					//ft_printf("z.a_2next = %d and z.a_next = %d\n", z.a_2next, z.a_next);*/
					//if (vec_int(a, z.a_2next) > vec_int(a, z.a_next) && vec_int(a, z.a_2next) < vec_int (b, b->len - 1))
					//	if (z.a_cost > 6)
					//		z.total_cost--;
					}
					
					//else	
						//else
							//z.total_cost--;
							
							//	z.total_cost *= 0.85;
							//else
							//	z.total_cost -= (z.a_cost * 0.5);
							//if they are in the same direction, total cost should just be halved.
							//if they are not, only the a part should be halved.
						
					
					//this one makes things worse
					//else if ((vec_int(a, z.a_prev) > vec_int(a, z.i) && vec_int(a, z.a_prev) < vec_int (b, b->len - 1)) && z.a_cost > z.b_cost)
					//	z.total_cost = (z.total_cost / 2) + 1;
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
int	execute_cheapest_push(t_vec *a, t_vec *b, int index_a, int index_b)
{
	smart_rotate(a, b, vec_int(a, index_a), vec_int(b, index_b));
	pb(a, b, 1);
	return (1);
}
int	batch_push(t_vec *a, t_vec *b)
{
	//ft_printf("attempting batch push\n");
	smart_rotate(a, b, find_max(a), find_max(b));
//	smart_rotate_b(b, find_max(b));
//	smart_rotate_a(a, find_max(a));
	//print_vector(a);
	//print_vector(b);
	//the else statement below is getting triggered far too often, creating an infinite loop. 
	//need to re-evaluate this.
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
		else if (vec_int(b, 0) > find_max(a))
		{
			smart_rotate_a(a, find_min(a, find_max(a)));
			pa(a, b, 1);
			sa(a, 1);
		}
		else if (vec_int(b, 0) < find_min(a, find_max(a)))
		{
			smart_rotate_a(a, find_min(a, find_max(a)));
			pa(a, b, 1);
		}
		else
			rra(a, 1);
	//print_vector(a);
	//print_vector(b);
	}
	return (1);
}
