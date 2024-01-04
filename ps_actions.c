/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_actions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rboudwin <rboudwin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 11:22:05 by rboudwin          #+#    #+#             */
/*   Updated: 2024/01/04 13:20:14 by rboudwin         ###   ########.fr       */
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
	ft_printf("sa\n");
	ft_printf("0 and 1 positions are '%d' and '%d' respectively\n", *ptr_0, *ptr_1);
	tmp = *ptr_1;
	*ptr_1 = *ptr_0;
	*ptr_0 = tmp;
	ft_printf("0 and 1 positions are now '%d' and '%d' respectively\n", *ptr_0, *ptr_1);
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
	ft_printf("sb\n");
	ft_printf("0 and 1 positions are '%d' and '%d' respectively\n", *ptr_0, *ptr_1);
	tmp = *ptr_1;
	*ptr_1 = *ptr_0;
	*ptr_0 = tmp;
	ft_printf("0 and 1 positions are now '%d' and '%d' respectively\n", *ptr_0, *ptr_1);
	return (1);
}

/* ss : sa and sb at the same time.*/
int ss(t_vec *a, t_vec *b)
{
	sa(a);
	sb(b);
	return (1);
}

/* pa (push a): Take the first element at the top of b and put it at the top of a.
Do nothing if b is empty.*/
int	pa(t_vec *a, t_vec *b)
{
	vec_insert(a, vec_get(b, 0), 0);
	vec_remove(b, 0);
	return (1);
}

/* pb (push b): Take the first element at the top of a and put it at the top of b.
Do nothing if a is empty.*/
int	pb(t_vec *a, t_vec *b)
{
	vec_insert(b, vec_get(a, 0), 0);
	vec_remove(a, 0);
	return (1);
}

/* ra (rotate a): Shift up all elements of stack a by 1.
The first element becomes the last one.*/
int	ra(t_vec *a);

/* rb (rotate b): Shift up all elements of stack b by 1.
The first element becomes the last one.*/
int	rb(t_vec *b);

/*rr : ra and rb at the same time.*/
int	rr(t_vec *a, t_vec *b);

/*rra (reverse rotate a): Shift down all elements of stack a by 1.
The last element becomes the first one.*/
int	rra(t_vec *a);

/*rrb (reverse rotate b): Shift down all elements of stack b by 1.
The last element becomes the first one.*/
int	rrb(t_vec *b);

/*rrr : rra and rrb at the same time.*/
int	rrr(t_vec *a, t_vec *b);
