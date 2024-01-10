/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_actions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rboudwin <rboudwin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 11:22:05 by rboudwin          #+#    #+#             */
/*   Updated: 2024/01/10 10:09:33 by rboudwin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*sa (swap a): Swap the first 2 elements at the top of stack a.
Do nothing if there is only one or no elements.*/
int	sa(t_vec *a)
{
	int *ptr_0;
	int *ptr_1;
	int	tmp;
	ptr_0 = vec_get(a, 0);
	ptr_1 = vec_get(a, 1);
	if (!ptr_0 || !ptr_1)
		return (-1);
	tmp = *ptr_1;
	*ptr_1 = *ptr_0;
	*ptr_0 = tmp;
	return (1);
}

/* sb (swap b): Swap the first 2 elements at the top of stack b.
Do nothing if there is only one or no elements.*/
int	sb(t_vec *b)
{
	int *ptr_0;
	int *ptr_1;
	int	tmp;
	ptr_0 = vec_get(b, 0);
	ptr_1 = vec_get(b, 1);
	if (!ptr_0 || !ptr_1)
		return (-1);
	tmp = *ptr_1;
	*ptr_1 = *ptr_0;
	*ptr_0 = tmp;
	return (1);
}

/* ss : sa and sb at the same time.*/
int ss(t_vec *a, t_vec *b)
{
	if (sa(a) == -1 || sb(b) == -1)
		return (-1);
	return (1);
}

/* pa (push a): Take the first element at the top of b and put it at the top of a.
Do nothing if b is empty.*/
int	pa(t_vec *a, t_vec *b)
{
	int *ptr;
	
	ptr = vec_get(b,0);
	if (!ptr)
		return (-1);
	if (vec_insert(a, ptr, 0) == -1 || vec_remove(b, 0) == -1)
		return (-1);
	return (1);
}

/* pb (push b): Take the first element at the top of a and put it at the top of b.
Do nothing if a is empty.*/
int	pb(t_vec *a, t_vec *b)
{
	int *ptr;

	ptr = vec_get(a, 0);
	if (!ptr)
		return (-1);
	if (vec_insert(b, ptr, 0) == -1 || vec_remove(a, 0) == -1)
		return (-1);
	return (1);
}

/* ra (rotate a): Shift up all elements of stack a by 1.
The first element becomes the last one.*/
int	ra(t_vec *a)
{
	int *ptr;

	ptr = vec_get(a, 0);
	if (!ptr || vec_push(a, ptr) == -1 || vec_remove(a, 0) == -1)
		return (-1);
	return (1);
}

/* rb (rotate b): Shift up all elements of stack b by 1.
The first element becomes the last one.*/
int	rb(t_vec *b)
{
	int *ptr;

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
	int x;
	int *ptr;

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
	int x;
	int *ptr;
	
	ptr = vec_get(b, b->len - 1);
	if (!ptr)
		return (-1);
	x = *(int *)(ptr);
	if (vec_insert(b, &x, 0) == -1 || vec_remove(b, b->len - 1) == -1)
		return (-1);
	return (1);
}

/*rrr : rra and rrb at the same time.*/
int	rrr(t_vec *a, t_vec *b)
{
	if (rra(a) == -1 || rrb(b) == -1)
		return (-1);
	return (1);
}
