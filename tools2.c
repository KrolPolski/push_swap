/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rboudwin <rboudwin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 11:23:28 by rboudwin          #+#    #+#             */
/*   Updated: 2024/01/25 11:48:17 by rboudwin         ###   ########.fr       */
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

//we want to rotate to get the target 
//value on top, but we don't know which direction will be more efficient yet.
//We can use the index, distance from 0 or distance from len - 1
int	smart_rotate_a(t_vec *a, int target)
{
	int		from_zero;
	int		from_end;
	size_t	i;

	from_zero = a->len;
	from_end = a->len;
	i = 0;
	while (i < a->len && vec_int(a, i) != target)
	{
		i++;
	}
	if (vec_int(a, i) == target)
	{
		from_zero = i;
		from_end = a->len - 1 - i;
	}
	if (from_zero <= from_end)
	{
		while (i > 0)
		{
			ra(a, 1);
			i--;
		}
	}
	else
		i = a->len - i;
	while (i > 0)
	{
		rra(a, 1);
		i--;
	}
	return (1);
}

int	smart_rotate_b(t_vec *b, int target)
{
	int		from_zero;
	int		from_end;
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
	i = 0;
	k = 0;
	while (i < a->len && vec_int(a, i) != a_target)
		i++;
	while (k < b->len && vec_int(b, k) != b_target)
		k++;
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
	}
	else if (a_from_zero > a_from_end && b_from_zero >= b_from_end)
	{
		while (i < a->len && k < b->len)
		{
			rrr(a, b, 1);
			i++;
			k++;
		}
	}
	smart_rotate_a(a, a_target);
	smart_rotate_b(b, b_target);
	return (1);
}

int	find_min(t_vec *a, int max)
{
	size_t	index;
	int		min;

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
