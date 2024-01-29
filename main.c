/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rboudwin <rboudwin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 18:10:32 by rboudwin          #+#    #+#             */
/*   Updated: 2024/01/29 14:07:19 by rboudwin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//detect duplicate values and return an error
void	detect_duplicates(t_vec *a, t_vec *b)
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
//	print_vector(&a);
	detect_duplicates(&a, &b);
	check_order(&a, &b);
	push_swap(&a, &b);
	vec_free(&a);
	vec_free(&b);
}
