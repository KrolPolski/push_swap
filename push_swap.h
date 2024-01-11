/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rboudwin <rboudwin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 13:15:40 by rboudwin          #+#    #+#             */
/*   Updated: 2024/01/11 18:21:51 by rboudwin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "Libft/libft.h"

/*sa (swap a): Swap the first 2 elements at the top of stack a.
Do nothing if there is only one or no elements.*/
int	sa(t_vec *a, int print);

/* sb (swap b): Swap the first 2 elements at the top of stack b.
Do nothing if there is only one or no elements.*/
int	sb(t_vec *b, int print);

/* ss : sa and sb at the same time.*/
int	ss(t_vec *a, t_vec *b, int print);

/* pa (push a): Take the first element 
at the top of b and put it at the top of a.
Do nothing if b is empty.*/
int	pa(t_vec *a, t_vec *b, int print);

/* pb (push b): Take the first element 
at the top of a and put it at the top of b.
Do nothing if a is empty.*/
int	pb(t_vec *a, t_vec *b, int print);

/* ra (rotate a): Shift up all elements of stack a by 1.
The first element becomes the last one.*/
int	ra(t_vec *a, int print);

/* rb (rotate b): Shift up all elements of stack b by 1.
The first element becomes the last one.*/
int	rb(t_vec *b, int print);

/*rr : ra and rb at the same time.*/
int	rr(t_vec *a, t_vec *b, int print);

/*rra (reverse rotate a): Shift down all elements of stack a by 1.
The last element becomes the first one.*/
int	rra(t_vec *a, int print);

/*rrb (reverse rotate b): Shift down all elements of stack b by 1.
The last element becomes the first one.*/
int	rrb(t_vec *b, int print);

/*rrr : rra and rrb at the same time.*/
int	rrr(t_vec *a, t_vec *b, int print);

int	print_vector(t_vec *vec);
int	check_order(t_vec *a);
int	push_swap_three(t_vec *a);
int	vec_int(t_vec *a, int index);
int	push_swap_small(t_vec *a, t_vec *b);
int	push_swap_medium(t_vec *a, t_vec *b);
int	find_max(t_vec *a);
int	find_min(t_vec *a, int max);
int	smart_rotate(t_vec *a, int target);
#endif
