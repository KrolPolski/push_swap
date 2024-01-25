/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rboudwin <rboudwin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 18:10:32 by rboudwin          #+#    #+#             */
/*   Updated: 2024/01/25 11:56:08 by rboudwin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
void	handle_split(int *argc, char **argv, int *i)
{
	if (*argc == 2)
	{
		if (!argv[1][0])
		{
			ft_putstr_fd("Error\n", 2);
			exit(EXIT_FAILURE);
		}
		argv = ft_split(argv[1], ' ');
		if (!argv)
		{
			ft_putstr_fd("Error\n", 2);
			exit(EXIT_FAILURE);
		}
		*i = 0;
		*argc = 0;
		while (argv[*i] != NULL)
		{
			(*argc)++;
			(*i)++;
		}
		*i = 0;
	}
}

int	convert_and_build_vector(t_vec *a, int argc, char **argv)
{
	long	tmp;
	int		int_tmp;
	int		i;
	int		*ptr;

	i = 1;
	handle_split(&argc, argv, &i);
	while (i < argc)
	{
		if (argv[i][0] != '-' && (argv[i][0] < 48 || argv[i][0] > 57))
		{
			vec_free(a);
			return (-1);
		}
		tmp = ft_long_atoi(argv[i]);
		if (tmp > 2147483647 || tmp < -2147483648)
			return (-1);
		int_tmp = (int)tmp;
		vec_push(a, &int_tmp);
		ptr = vec_get(a, i - 1);
		i++;
	}
	return (1);
}

//detect duplicate values and return an error
void	validate_input(t_vec *a, t_vec *b)
{
	unsigned long	i;
	unsigned long	k;

	i = 0;
	k = 1;
	while (i < a->len - 1)
	{
		while (k < a->len)
		{
			if (vec_int(a, i) == vec_int(a, k))
			{
				vec_free(a);
				vec_free(b);
				ft_putstr_fd("Error\n", 2);
				exit(-1);
			}
			k++;
		}
		i++;
		k = i + 1;
	}
}

int	main(int argc, char **argv)
{
	int		ret;
	t_vec	a;
	t_vec	b;

	if (argc < 2)
	{
		ft_putstr_fd("Error\n", 2);
		exit(-1);
	}
	vec_new(&a, 0, sizeof(int));
	vec_new(&b, 0, sizeof(int));
	ret = convert_and_build_vector(&a, argc, argv);
	if (ret == -1)
	{
		ft_putstr_fd("Error\n", 2);
		exit(-1);
	}
	validate_input(&a, &b);
	check_order(&a, &b);
	push_swap(&a, &b);
	vec_free(&a);
	vec_free(&b);
}
