/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rboudwin <rboudwin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 13:15:33 by rboudwin          #+#    #+#             */
/*   Updated: 2024/01/03 12:23:58 by rboudwin         ###   ########.fr       */
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
int	*convert_and_build_array(int argc, char **argv)
{
	int *a;
	int	tmp;
	int	i;

	i = 1;
	a = malloc(argc * sizeof(int));
	if (!a)
		return (NULL);
	while (i < argc)
	{
		if (argv[i][0] < 48 || argv[i][0] > 57)
		{
			free(a);
			a = NULL;
			return (NULL);
		}
		tmp = ft_atoi(argv[i]);
		a[i * sizeof(int)] = tmp;
		ft_printf("%d, ", a[i * sizeof(int)]);
		i++;
	}
	return (a);
}
int	main(int argc, char **argv)
{
	int *a;

	if (argc < 2)
		ft_putstr_fd("Error\n", 2);
	a = convert_and_build_array(argc, argv);
	if (!a)
		ft_putstr_fd("Error\n", 2);
}
