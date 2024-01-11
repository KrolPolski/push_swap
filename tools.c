/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rboudwin <rboudwin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 11:47:06 by rboudwin          #+#    #+#             */
/*   Updated: 2024/01/11 18:25:58 by rboudwin         ###   ########.fr       */
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
/*int	smart_rotate(t_vec *a, int target)
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
	if (vec_int(a, i) == target)
	{
		from_zero = i;
		from_end = a->len - 1 - i;
	}
	if (from_zero >= from_end)
		//rotate using ra(a) i number of times
	else
		//rotate using rra(a) a->len - i number of times
}*/