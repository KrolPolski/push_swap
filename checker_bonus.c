/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rboudwin <rboudwin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 15:18:31 by rboudwin          #+#    #+#             */
/*   Updated: 2024/01/29 15:37:43 by rboudwin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
int	checker_order(t_vec *a, t_vec *b)
{
	int	i;
	int	in_order;

	i = 1;
	in_order = 1;
	while (i < (int)a->len)
	{
		if (vec_int(a, i -1 ) > vec_int(a, i))
			in_order = 0;
		i++;
	}
	if (b->len != 0)
		in_order = 0;
	return (in_order);
}
int	checker(t_vec *a, t_vec *b)
{
	char	*str;
//add check for invalid operations, pushing empty stacks, swapping when we don't have two, etc. anything that could segfault
	
	str = get_next_line(0);
	while (str)
	{
		if (ft_strncmp(str, "ra\n", ft_strlen(str)) == 0)
			ra(a, 0);
		else if (ft_strncmp(str, "rb\n", ft_strlen(str)) == 0)
			rb(b, 0);
		else if (ft_strncmp(str, "sa\n", ft_strlen(str)) == 0)
			sa(a, 0);
		else if (ft_strncmp(str, "sb\n", ft_strlen(str)) == 0)
			sb(b, 0);
		else if (ft_strncmp(str, "rra\n", ft_strlen(str)) == 0)
			rra(a, 0);
		else if (ft_strncmp(str, "rrb\n", ft_strlen(str)) == 0)
			rrb(b, 0);
		else if (ft_strncmp(str, "pa\n", ft_strlen(str)) == 0)
			pa(a, b, 0);
		else if (ft_strncmp(str, "pb\n", ft_strlen(str)) == 0)
			pb(a, b, 0);
		else if (ft_strncmp(str, "rr\n", ft_strlen(str)) == 0)
			rr(a, b, 0);
		else if (ft_strncmp(str, "ss\n", ft_strlen(str)) == 0)
			ss(a, b, 0);
		else if (ft_strncmp(str, "rrr\n", ft_strlen(str)) == 0)
			rrr(a, b, 0);
		else
		{
			free(str);
			vec_free(a);
			vec_free(b);
			ft_putstr_fd("Error\n", 2);
			exit(EXIT_FAILURE);
		}
		free(str);
		str = get_next_line(0);
	}
	if (!checker_order(a, b))
	{
		write(1, "KO", 2);
		vec_free(a);
		vec_free(b);
		exit(EXIT_FAILURE);
	}
	else
		write(1, "OK", 2);
	vec_free(a);
	vec_free(b);
	exit(EXIT_SUCCESS);
}
int	main(int argc, char **argv)
{
	int		ret;
	t_vec	a;
	t_vec	b;

	if (argc < 2)
	{
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
	detect_duplicates(&a, &b);
	//check_order(&a, &b);
	//here it diverges
	checker(&a, &b);
	//push_swap(&a, &b);
	vec_free(&a);
	vec_free(&b);
	exit(EXIT_SUCCESS);
}