/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_vector.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rboudwin <rboudwin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 12:43:19 by rboudwin          #+#    #+#             */
/*   Updated: 2024/01/30 14:31:59 by rboudwin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*Frees argv in the event it was overwritten by our handle_split*/
void	free_argv(char **argv, t_cbv *cbv)
{
	int	i;

	i = 0;
	while (argv[i] != NULL && cbv->free_req == 1)
	{
		free(argv[i]);
		i++;
	}
	if (cbv->free_req == 1)
		free(argv);
	cbv->free_req = 0;
}

/*handles the case of all the arguments given as a
 single space delimited string*/
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
		if (!ft_strchr(argv[1], ' '))
			return (NULL);
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

/*Checks for non numeric characters or more than one - sign*/
int	validate_input(t_cbv *cbv, t_vec *a, char **argv)
{
	cbv->k = 0;
	while (argv[cbv->i][cbv->k] != '\0')
	{
		if (argv[cbv->i][cbv->k] == '-' && cbv->k == 0
			&& argv[cbv->i][cbv->k + 1] != '\0')
			cbv->k++;
		else if (argv[cbv->i][cbv->k] < 48 || argv[cbv->i][cbv->k] > 57)
		{
			vec_free(a);
			if (cbv->free_req == 1)
			{
				free_argv(argv, cbv);
			}
			return (-1);
		}
		else
			cbv->k++;
	}
	return (1);
}

char	**init_cbv(t_cbv *cbv, int *argc, char **argv)
{
	cbv->i = 1;
	cbv->k = 0;
	cbv->free_req = 0;
	cbv->result = handle_split(argc, argv, &cbv->i);
	if (cbv->result)
	{
		cbv->free_req = 1;
		return (cbv->result);
	}
	return (argv);
}

int	convert_and_build_vector(t_vec *a, int argc, char **argv)
{
	t_cbv	cbv;

	argv = init_cbv(&cbv, &argc, argv);
	while (cbv.i < argc)
	{
		if (validate_input(&cbv, a, argv) == -1)
			return (-1);
		cbv.tmp = ft_long_atoi(argv[cbv.i]);
		if (cbv.tmp > 2147483647 || cbv.tmp < -2147483648)
		{
			if (cbv.free_req)
			{
				free_argv(argv, &cbv);
			}
			return (-1);
		}
		cbv.int_tmp = (int)cbv.tmp;
		vec_push(a, &cbv.int_tmp);
		cbv.i++;
	}
	if (cbv.free_req)
		free_argv(argv, &cbv);
	return (1);
}
