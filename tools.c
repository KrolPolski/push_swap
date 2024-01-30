/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rboudwin <rboudwin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 09:33:17 by rboudwin          #+#    #+#             */
/*   Updated: 2024/01/30 14:39:14 by rboudwin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	print_vector(t_vec *vec)
{
	size_t	i;

	i = 0;
	while (i < vec->len)
	{
		ft_printf("%d, ", vec_int(vec, i));
		i++;
	}
	ft_printf("\n");
	return (1);
}

void	check_order(t_vec *a, t_vec *b)
{
	size_t	i;
	int		in_order;

	i = 1;
	in_order = 1;
	while (i < a->len)
	{
		if (vec_int(a, i - 1) > vec_int(a, i))
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

/*Returns the integer at any vector position*/
int	vec_int(t_vec *a, int index)
{
	int	*ptr;
	int	x;

	ptr = vec_get(a, index);
	x = *ptr;
	return (x);
}

/*returns index of any int value*/
int	vec_int_to_index(t_vec *a, int x)
{
	size_t	i;

	i = 0;
	while (i < a->len)
	{
		if (vec_int(a, i) == x)
			return (i);
		i++;
	}
	return (-1);
}

int	find_max(t_vec *a)
{
	size_t	index;
	int		max;

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
