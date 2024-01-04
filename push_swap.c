/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rboudwin <rboudwin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 13:15:33 by rboudwin          #+#    #+#             */
/*   Updated: 2024/01/04 11:59:51 by rboudwin         ###   ########.fr       */
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
	int	tmp;
	int	i;
	int *ptr;

	i = 1;
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

int	push_swap_small(t_vec *a, t_vec *b)
{
	
}

int	push_swap(t_vec *a, t_vec *b)
{
	sa(a);
	pb(a, b);
	//pb(a, b);
	ft_printf("a and b are now: \n");
	print_vector(a);
	print_vector(b);
	//sb(b);
	ft_printf("a and b are now: \n");
	print_vector(a);
	print_vector(b);
	//if (a->len < 4)
	//	push_swap_small(a, b);
	/*if (a->len < 10)
		push_swap_medium(a, b);
	if (a->len < 100)
		push_swap_large(a, b);
	if (a->len >= 100)
		push_swap_jumbo(a, b);*/
}
int	main(int argc, char **argv)
{
	int ret;
	t_vec a;
	t_vec b;

	if (argc < 2)
		ft_putstr_fd("Error\n", 2);
	vec_new(&a, 1, sizeof(int));
	vec_new(&b, 1, sizeof(int));
	ret = convert_and_build_vector(&a, argc, argv);
	print_vector(&a);
	if (ret == -1)
		ft_putstr_fd("Error\n", 2);
	//if we get here we can assume arguments are clean
	push_swap(&a, &b);
	vec_free(&a);
	vec_free(&b);
}
