/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_actions2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rboudwin <rboudwin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 10:10:21 by rboudwin          #+#    #+#             */
/*   Updated: 2024/01/10 10:12:24 by rboudwin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* ra (rotate a): Shift up all elements of stack a by 1.
The first element becomes the last one.*/
int	ra(t_vec *a)
{
	int	*ptr;

	ptr = vec_get(a, 0);
	if (!ptr || vec_push(a, ptr) == -1 || vec_remove(a, 0) == -1)
		return (-1);
	return (1);
}

/* rb (rotate b): Shift up all elements of stack b by 1.
The first element becomes the last one.*/
int	rb(t_vec *b)
{
	int	*ptr;

	ptr = vec_get(b, 0);
	if (!ptr || vec_push(b, ptr) == -1 || vec_remove(b, 0) == -1)
		return (-1);
	return (1);
}

/*rr : ra and rb at the same time.*/
int	rr(t_vec *a, t_vec *b)
{
	if (ra(a) == -1 || rb(b) == -1)
		return (-1);
	return (1);
}

/*rra (reverse rotate a): Shift down all elements of stack a by 1.
The last element becomes the first one.*/
int	rra(t_vec *a)
{
	int	x;
	int	*ptr;

	ptr = vec_get(a, a->len - 1);
	if (!ptr)
		return (-1);
	x = *(int *)(ptr);
	if (vec_insert(a, &x, 0) == -1 || vec_remove(a, a->len - 1) == -1)
		return (-1);
	return (1);
}

/*rrb (reverse rotate b): Shift down all elements of stack b by 1.
The last element becomes the first one.*/
int	rrb(t_vec *b)
{
	int	x;
	int	*ptr;

	ptr = vec_get(b, b->len - 1);
	if (!ptr)
		return (-1);
	x = *(int *)(ptr);
	if (vec_insert(b, &x, 0) == -1 || vec_remove(b, b->len - 1) == -1)
		return (-1);
	return (1);
}


