/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rboudwin <rboudwin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 09:33:17 by rboudwin          #+#    #+#             */
/*   Updated: 2024/01/24 12:31:02 by rboudwin         ###   ########.fr       */
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
int	choose_cheapest_push(t_vec *a, t_vec *b)
{
	t_ccp	z;
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
	//ft_printf("a->len is %d and b->len is %d\n", a->len, b->len);
	//find_0(b);
	//if (vec_int(b, 0) == 73)
		//ft_printf("About to move on after pushing 73\n");
	while (z.i < a->len)
	{
		
	//print_vector(a);
	//print_vector(b);
		//ft_printf("inside i loop and i is %d and a->len is %d\n", z.i, a->len);
		while (z.k < b->len)
		{
			if (z.k == 0)
				z.next = b->len - 1;
			else
				z.next = z.k - 1;
		//	ft_printf("the current value of next (b, %d) is %d\n", z.next, vec_int(b, z.next));
			//we are also not yet considering b_costs. I guess we are indirectly.
			//not considering reverse costs of b either.
		//	ft_printf("vec_int(a, %d) is %d and z.b_min is %d\n", z.i, vec_int(a, z.i), z.b_min);
			//ft_printf("vec_int(b, %d) is %d\n and vec_int(b, %d) is %d\n", z.k, vec_int(b, z.k), z.next, vec_int(b, z.next));
			//ft_printf("else if (vec_int(a, z.i%d) > vec_int(b, z.k) && vec_int(a, z.i) < vec_int (b, z.next))")
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
				else {
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
					z.index_b = z.k;
				}
			}
			z.k++;
		}
	z.k = 0;
	z.i++;
	}
	//by now we have figured out the cheapest simple push. need to check if rotating b can drop the cost further	

	//ft_printf("We exited i loop\n");
	if (z.index_a >= a->len || z.index_b >= b->len)
	{
		//this should not be necessary
		//ft_printf("Invalid index, forcing min max choose_cheapest_push\n");
		//do something else here. some case is not being handled.
		//return (-1);
		//might be less than everything, might be more than everything.
	}
	//ft_printf("We have concluded that the cheapest push will be from index_a %d (%d)to index_b %d (%d)\n", index_a, vec_int(a, index_a), index_b, vec_int(b, index_b));
//	if (vec_int(a, index_a) == 73)
			//ft_printf("a, %d is currently 73\n", i);
//	ft_printf("about to call execute_cheapest_push\n");
	execute_cheapest_push(a, b, z.index_a, z.index_b);
	return (1);
}
int	execute_cheapest_push(t_vec *a, t_vec *b, int index_a, int index_b)
{
	//ft_printf("a_index: %d b_index: %d\n", index_a, index_b);
	//need to add logic to double rotate when possible, for now not worrying about it
//	ft_printf("We entered execute_cheapest_push\n");
	smart_rotate(a, b, vec_int(a, index_a), vec_int(b, index_b));
	//smart_rotate_a(a, vec_int(a, index_a));
	//smart_rotate_b(b, vec_int(b, index_b));
	pb(a, b, 1);
	return (1);
}
int	batch_push(t_vec *a, t_vec *b)
{
	//ft_printf("attempting batch push\n");
	smart_rotate_b(b, find_max(b));
	smart_rotate_a(a, find_max(a));
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
