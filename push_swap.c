/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rboudwin <rboudwin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 13:15:33 by rboudwin          #+#    #+#             */
/*   Updated: 2024/01/12 13:26:34 by rboudwin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*	The plan:
	1. Decide on data types. Do arrays make sense here? Or do I need a vector?
	2. Convert argv to integers and form them into an array
	3. make two arrays of max size + 1
	4. handle invalid arguments, not enough arguments, etc.
	5. Write a function for each push_swap instruction
	6. Write logic to decide how to choose which instruction for what situation
*/

/* Parse the arguments and add them as elements to the vector */
int	convert_and_build_vector(t_vec *a, int argc, char **argv)
{
	// we need to build in logic that will 
	//handle arguments being passed in quotes
	// like this: "1 2 3" instead of 1 2 3
	int	tmp;
	int	i;
	int *ptr;

	i = 1;
	if (argc == 2)
	{
		argv = ft_split(argv[1], ' ');
		if (!argv)
			return (-1);
		//this works but isn't super clear, there has to be a
		// cleaner solution than screwing with argc and i
		i = 0;
		argc = 0;
		while (argv[i] != NULL)
		{
			argc++;
			i++;
		}
		i = 0;
	}
	while (i < argc)
	{
		if (argv[i][0] < 48 || argv[i][0] > 57)
		{
			vec_free(a);
			return (-1);
		}
		tmp = ft_atoi(argv[i]);
		vec_push(a, &tmp);
		ptr = vec_get(a, i - 1);
		//ft_printf("%d, ", *ptr);
		i++;
	}
	return (1);
}
//this one is simple enough to hardcode
int	push_swap_three(t_vec *a)
{
	if (vec_int(a, 0) > vec_int(a, 1) && vec_int(a, 2) > vec_int(a, 0))
	{
		sa(a, 1);
		return (1);
	}
	else if (vec_int(a, 0) < vec_int(a, 1) && vec_int(a, 2) < vec_int(a, 0))
	{
		rra(a, 1);
		return (1);
	}
	else if (vec_int(a, 1) < vec_int(a, 2) && vec_int(a, 0) > vec_int(a, 2))
	{
		ra(a, 1);
		return (1);
	}
	else if (vec_int(a, 0) > vec_int(a, 1) && vec_int(a, 1) > vec_int(a, 2))
	{
		sa(a, 1);
		rra(a, 1);
		return (1);
	}
	else if (vec_int(a, 0) > vec_int(a, 1) && vec_int(a, 2) > vec_int(a, 0))
	{
		sa(a, 1);
		ra(a, 1);
		return (1);
	}
	else
		ft_printf("Something went wrong in push_swap_three");
	return (-1);
}

//we need to handle 2, or 3 numbers.
int	push_swap_small(t_vec *a, t_vec *b)
{
	int	i;
	int	index;

	i = 0;
	if (a->len == 2)
	{
		if (*(int *)vec_get(a, 0) > *(int *)vec_get(a, 1))
		{
			sa(a, 1);
			return (1);
		}
		else
			return (1);
	}
	else
		push_swap_three(a);
	return (1);
	
}

int	push_swap_medium(t_vec *a, t_vec *b)
{
	int	max;
	int	min;
	int	midpoint;
	int index;

	index = 0;
	max = find_max(a);
	min = find_min(a, max);
	midpoint = min + ((max - min) / 2);
	//ft_printf("The min is %d and the max is %d\n", min, max);
	pb(a, b, 1);
	pb(a, b, 1);
	if (vec_int(a, 0) > vec_int(a, 1) && vec_int(b, 0) < vec_int(b, 1))
	{
		ss(a, b, 1);
	}
	else if (vec_int(b, 0) < vec_int(b, 1))
	{
		sb(b, 1);
	}
	while (vec_int(a, 0) < vec_int(b, 0))
	{
		ra(a, 1);
	}
}
int	push_swap(t_vec *a, t_vec *b)
{
	/*tests:
	sa(a);
	pb(a, b);
	ft_printf("length of a is %d and b is %d\n", a->len, b->len);
	ft_printf("allocation size of b is %d and elem size is %d\n", b->alloc_size, b->elem_size);
	
	ft_printf("a and b are now: \n");
	print_vector(a);
	print_vector(b);
	pb(a, b);
	sb(b);

	ft_printf("a and b are now: \n");
	print_vector(a);
	print_vector(b);
	ra(a);
	ft_printf("After ra: ");
	print_vector(a);
	rra(a);
	ft_printf("After rra: ");
	print_vector(a);
	rb(b);
	ft_printf("After rb: ");
	print_vector(b);
	rrb(b);
	ft_printf("After rrb: ");
	print_vector(b);
	rrr(a, b);
	ft_printf("After rrr: ");
	print_vector(a);
	print_vector(b);*/
	if (a->len == 1)
		return (1);
	if (a->len < 4)
		push_swap_small(a, b);
	else if (a->len < 10)
		push_swap_medium(a, b);/*
	if (a->len < 100)
		push_swap_large(a, b);
	if (a->len >= 100)
		push_swap_jumbo(a, b);*/
	return (1);
}
int	main(int argc, char **argv)
{
	int ret;
	t_vec a;
	t_vec b;

	if (argc < 2)
	{
		ft_putstr_fd("Error\n", 2);
		exit(-1);
	}
	vec_new(&a, 0, sizeof(int));
	vec_new(&b, 0, sizeof(int));
	ret = convert_and_build_vector(&a, argc, argv);
	//print_vector(&a);
	//smart_rotate(&a, 5);
	//print_vector(&a);
	if (ret == -1)
	{
		ft_putstr_fd("Error\n", 2);
		exit(-1);
	}
	if (check_order(&a) == 1)
	{
		vec_free(&a);
		vec_free(&b);
		exit(1);
	}
	//if we get here we can assume arguments are clean
//	ft_printf("about to enter push_swap function\n");
	push_swap(&a, &b);
	vec_free(&a);
	vec_free(&b);
}
