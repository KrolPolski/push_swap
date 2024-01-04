/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rboudwin <rboudwin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 13:15:33 by rboudwin          #+#    #+#             */
/*   Updated: 2024/01/04 11:13:01 by rboudwin         ###   ########.fr       */
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
		ft_printf("%d, ", *ptr);
		i++;
	}
	return (1);
}
int	main(int argc, char **argv)
{
	int ret;
	t_vec a;

	if (argc < 2)
		ft_putstr_fd("Error\n", 2);
	vec_new(&a, 1, sizeof(int));
	ret = convert_and_build_vector(&a, argc, argv);
	if (ret == -1)
		ft_putstr_fd("Error\n", 2);
	vec_free(&a);
}
