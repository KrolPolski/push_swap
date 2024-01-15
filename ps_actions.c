/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_actions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rboudwin <rboudwin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 15:17:47 by rboudwin          #+#    #+#             */
/*   Updated: 2024/01/15 15:17:49 by rboudwin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "push_swap.h"

/*sa (swap a): Swap the first 2 elements at the top of stack a.
Do nothing if there is only one or no elements.*/
int	sa(t_vec *a, int print)
{
	int	*ptr_0;
	int	*ptr_1;
	int	tmp;

	ptr_0 = vec_get(a, 0);
	ptr_1 = vec_get(a, 1);
	if (!ptr_0 || !ptr_1)
		return (-1);
	tmp = *ptr_1;
	*ptr_1 = *ptr_0;
	*ptr_0 = tmp;
	if (print)
		ft_printf("sa\n");
	return (1);
}

/* sb (swap b): Swap the first 2 elements at the top of stack b.
Do nothing if there is only one or no elements.*/
int	sb(t_vec *b, int print)
{
	int	*ptr_0;
	int	*ptr_1;
	int	tmp;

	ptr_0 = vec_get(b, 0);
	ptr_1 = vec_get(b, 1);
	if (!ptr_0 || !ptr_1)
		return (-1);
	tmp = *ptr_1;
	*ptr_1 = *ptr_0;
	*ptr_0 = tmp;
	if (print)
		ft_printf("sb\n");
	return (1);
}

/* ss : sa and sb at the same time.*/
int ss(t_vec *a, t_vec *b, int print)
{
	if (sa(a, 0) == -1 || sb(b, 0) == -1)
		return (-1);
	if (print)
		ft_printf("ss\n");
	return (1);
}

/* pa (push a): Take the first element at the 
top of b and put it at the top of a.
Do nothing if b is empty.*/
int	pa(t_vec *a, t_vec *b, int print)
{
	int	*ptr;

	ptr = vec_get(b,0);
	if (!ptr)
		return (-1);
	if (vec_insert(a, ptr, 0) == -1 || vec_remove(b, 0) == -1)
		return (-1);
	if (print)
		ft_printf("pa\n");
	return (1);
}

/* pb (push b): Take the first element at 
the top of a and put it at the top of b.
Do nothing if a is empty.*/
int	pb(t_vec *a, t_vec *b, int print)
{
	int	*ptr;

	ptr = vec_get(a, 0);
	if (!ptr)
		return (-1);
	if (vec_insert(b, ptr, 0) == -1 || vec_remove(a, 0) == -1)
		return (-1);
	if (print)
		ft_printf("pb\n");
	return (1);
}

