/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rboudwin <rboudwin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 09:33:17 by rboudwin          #+#    #+#             */
/*   Updated: 2024/01/24 18:19:39 by rboudwin         ###   ########.fr       */
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

void	check_order(t_vec *a, t_vec *b)
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
	if (in_order == 1)
	{
		vec_free(a);
		vec_free(b);
		exit(1);
	}
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
