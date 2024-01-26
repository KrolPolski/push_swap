/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rboudwin <rboudwin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 11:23:28 by rboudwin          #+#    #+#             */
/*   Updated: 2024/01/25 13:35:45 by rboudwin         ###   ########.fr       */
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
