/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_vector.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rboudwin <rboudwin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 12:43:19 by rboudwin          #+#    #+#             */
/*   Updated: 2024/01/29 12:50:48 by rboudwin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_argv(char **argv)
{
	int	i;

	i = 0;
	while (argv[i] != NULL)
	{
		free(argv[i]);
		i++;
	}
	free(argv);
}

char	**handle_split(int *argc, char **argv, int *i)
{
	char	**result;

	if (*argc == 2)
	{
		if (!argv[1][0])
		{
			ft_putstr_fd("Error\n", 2);
			exit(EXIT_FAILURE);
		}
		result = ft_split(argv[1], ' ');
		if (!result)
		{
			ft_putstr_fd("Error\n", 2);
			exit(EXIT_FAILURE);
		}
		*i = 0;
		*argc = 0;
		while (result[(*i)++] != NULL)
			(*argc)++;
		*i = 0;
		return (result);
	}
	return (NULL);
}

int	validate_input(t_cbv *cbv, t_vec *a, char **argv)
{
	cbv->k = 0;
	while (argv[cbv->i][cbv->k] != '\0')
	{
		if (argv[cbv->i][cbv->k] == '-' && cbv->k == 0)
			cbv->k++;
		else if (argv[cbv->i][cbv->k] < 48 || argv[cbv->i][cbv->k] > 57)
		{
			vec_free(a);
			if (cbv->free_req)
				free_argv(argv);
			return (-1);
		}
		else
			cbv->k++;
	}
	return (1);
}

void	init_cbv(t_cbv *cbv, int argc, char **argv)
{
	cbv->i = 1;
	cbv->k = 0;
	cbv->free_req = 0;
	cbv->result = handle_split(&argc, argv, &cbv->i);
	if (cbv->result)
	{
		cbv->free_req = 1;
		argv = cbv->result;
	}
}

int	convert_and_build_vector(t_vec *a, int argc, char **argv)
{
	t_cbv	cbv;

	init_cbv(&cbv, argc, argv);
	while (cbv.i < argc)
	{
		if (validate_input(&cbv, a, argv) == -1)
			return (-1);
		cbv.tmp = ft_long_atoi(argv[cbv.i]);
		if (cbv.tmp > 2147483647 || cbv.tmp < -2147483648)
		{
			if (cbv.free_req)
				free_argv(argv);
			return (-1);
		}
		cbv.int_tmp = (int)cbv.tmp;
		vec_push(a, &cbv.int_tmp);
		cbv.i++;
	}
	if (cbv.free_req)
		free_argv(argv);
	return (1);
}
