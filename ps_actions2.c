/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_actions2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rboudwin <rboudwin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 15:17:58 by rboudwin          #+#    #+#             */
/*   Updated: 2024/01/30 14:34:21 by rboudwin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ra(t_vec *a, int print)
{
	int	num;
	int	*ptr;

	num = vec_int(a, 0);
	ptr = &num;
	vec_remove(a, 0);
	vec_push(a, ptr);
	if (print == 1)
		ft_printf("ra\n");
	return (1);
}

/* rb (rotate b): Shift up all elements of stack b by 1.
The first element becomes the last one.*/
int	rb(t_vec *b, int print)
{
	int	num;
	int	*ptr;

	num = vec_int(b, 0);
	ptr = &num;
	vec_remove(b, 0);
	vec_push(b, ptr);
	if (print == 1)
		ft_printf("rb\n");
	return (1);
}

/*rr : ra and rb at the same time.*/
int	rr(t_vec *a, t_vec *b, int print)
{
	if (ra(a, 0) == -1 || rb(b, 0) == -1)
		return (-1);
	if (print)
		ft_printf("rr\n");
	return (1);
}

int	rra(t_vec *a, int print)
{
	int	num;
	int	*ptr;

	num = vec_int(a, a->len - 1);
	ptr = &num;
	vec_remove(a, a->len - 1);
	vec_insert(a, ptr, 0);
	if (print == 1)
		ft_printf("rra\n");
	return (1);
}

/*rrb (reverse rotate b): Shift down all elements of stack b by 1.
The last element becomes the first one.*/
int	rrb(t_vec *b, int print)
{
	int	num;
	int	*ptr;

	num = vec_int(b, b->len - 1);
	ptr = &num;
	vec_remove(b, b->len - 1);
	vec_insert(b, ptr, 0);
	if (print == 1)
		ft_printf("rrb\n");
	return (1);
}
