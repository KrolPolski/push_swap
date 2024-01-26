/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rboudwin <rboudwin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 15:18:21 by rboudwin          #+#    #+#             */
/*   Updated: 2024/01/25 13:41:20 by rboudwin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "Libft/libft.h"

typedef struct s_ccp
{
	int		a_cost;
	int		a_cost_forward;
	int		a_cost_reverse;
	int		b_cost;
	int		b_cost_forward;
	int		b_cost_reverse;
	int		min_a_cost;
	int		min_b_cost;
	int		total_cost;
	int		min_total_cost;
	size_t	index_a;
	size_t	index_b;
	size_t	i;
	size_t	k;
	int		next;
	size_t	a_next;
	size_t	a_2next;
	int		a_prev;
	int		b_max;
	int		b_min;
	int		b_max_index;
	int		b_min_index;
}	t_ccp;
typedef struct s_sr
{
	int		a_from_zero;
	int		a_from_end;
	int		b_from_zero;
	int		b_from_end;
	size_t	i;
	size_t	k;
}	t_sr;
/*sa (swap a): Swap the first 2 elements at the top of stack a.
Do nothing if there is only one or no elements.*/
int		sa(t_vec *a, int print);

/* sb (swap b): Swap the first 2 elements at the top of stack b.
Do nothing if there is only one or no elements.*/
int		sb(t_vec *b, int print);

/* ss : sa and sb at the same time.*/
int		ss(t_vec *a, t_vec *b, int print);

/* pa (push a): Take the first element 
at the top of b and put it at the top of a.
Do nothing if b is empty.*/
int		pa(t_vec *a, t_vec *b, int print);

/* pb (push b): Take the first element 
at the top of a and put it at the top of b.
Do nothing if a is empty.*/
int		pb(t_vec *a, t_vec *b, int print);

/* ra (rotate a): Shift up all elements of stack a by 1.
The first element becomes the last one.*/
int		ra(t_vec *a, int print);

/* rb (rotate b): Shift up all elements of stack b by 1.
The first element becomes the last one.*/
int		rb(t_vec *b, int print);

/*rr : ra and rb at the same time.*/
int		rr(t_vec *a, t_vec *b, int print);

/*rra (reverse rotate a): Shift down all elements of stack a by 1.
The last element becomes the first one.*/
int		rra(t_vec *a, int print);

/*rrb (reverse rotate b): Shift down all elements of stack b by 1.
The last element becomes the first one.*/
int		rrb(t_vec *b, int print);

/*rrr : rra and rrb at the same time.*/
int		rrr(t_vec *a, t_vec *b, int print);

int		print_vector(t_vec *vec);
void	check_order(t_vec *a, t_vec *b);
void	push_swap_three(t_vec *a);
int		vec_int(t_vec *a, int index);
int		push_swap_small(t_vec *a);
int		push_swap_five(t_vec *a, t_vec *b);
int		push_swap_medium(t_vec *a, t_vec *b);
int		find_max(t_vec *a);
int		find_min(t_vec *a, int max);
void	smart_rotate_a(t_vec *a, int target, t_sr *sr);
void	smart_rotate_b(t_vec *b, int target, t_sr *sr);
int		smart_rotate(t_vec *a, t_vec *b, int a_target, int b_target);
int		choose_cheapest_push(t_vec *a, t_vec *b);
void	execute_cheapest_push(t_vec *a, t_vec *b, int index_a, int index_b);
int		batch_push(t_vec *a, t_vec *b);
int		vec_int_to_index(t_vec *a, int x);
int		push_swap(t_vec *a, t_vec *b);
void	reverse_sort_three(t_vec *b);
#endif
