/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rboudwin <rboudwin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 15:17:15 by rboudwin          #+#    #+#             */
/*   Updated: 2024/01/23 12:39:29 by rboudwin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Parse the arguments and add them as elements to the vector */
int	convert_and_build_vector(t_vec *a, int argc, char **argv)
{
	long	tmp;
	int		int_tmp;
	int		i;
	int		*ptr;

	i = 1;
	if (argc == 2)
	{
		argv = ft_split(argv[1], ' ');
		if (!argv)
			return (-1);
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

void	reverse_sort_three(t_vec *b)
{
	if (vec_int(b, 0) > vec_int(b, 1) && vec_int(b, 2) > vec_int(b, 0))
		rrb(b, 1);
	else if (vec_int(b, 0) < vec_int(b, 1) && vec_int(b, 2) < vec_int(b, 0))
	{
		sb(b, 1);
	}
	else if (vec_int(b, 1) < vec_int(b, 2) && vec_int(b, 0) > vec_int(b, 2))
	{
		rrb(b, 1);
		sb(b, 1);
	}
	else if (vec_int(b, 0) > vec_int(b, 1) && vec_int(b, 1) > vec_int(b, 2))
		return ;
	else if (vec_int(b, 0) < vec_int(b, 1) && vec_int(b,1) < vec_int(b, 2))
	{
		rb(b, 1);
		sb(b, 1);
	}
	else if (vec_int(b, 0) < vec_int(b, 2) && vec_int(b, 2) < vec_int(b, 1))
		rb(b, 1);
}

void	push_swap_three(t_vec *a)
{
	if (vec_int(a, 0) < vec_int(a, 1) && vec_int(a, 1) < vec_int(a, 2))
		return ;
	if (vec_int(a, 0) > vec_int(a, 1) && vec_int(a, 2) > vec_int(a, 0))
	{
		sa(a, 1);
		return ;
	}
	else if (vec_int(a, 0) < vec_int(a, 1) && vec_int(a, 2) < vec_int(a, 0))
	{
		rra(a, 1);
		return ;
	}
	else if (vec_int(a, 1) < vec_int(a, 2) && vec_int(a, 0) > vec_int(a, 2))
	{
		ra(a, 1);
		return ;
	}
	else if (vec_int(a, 0) > vec_int(a, 1) && vec_int(a, 1) > vec_int(a, 2))
	{
		sa(a, 1);
		rra(a, 1);
		return ;
	}
	else if (vec_int(a, 0) > vec_int(a, 1) && vec_int(a, 2) > vec_int(a, 0))
	{
		sa(a, 1);
		ra(a, 1);
		return ;
	}
	else if (vec_int(a, 0) < vec_int(a, 1) && vec_int(a, 2) > vec_int(a, 0))
	{
		rra(a, 1);
		sa(a, 1);
	}
}

//we need to handle 2, or 3 numbers.
int	push_swap_small(t_vec *a)
{
	int	i;

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
int	push_swap_five(t_vec *a, t_vec *b)
{
	pb(a, b, 1);
	pb(a, b, 1);	
	push_swap_small(a);
	if (vec_int(b, b->len - 1) > vec_int(b, 0))
          sb(b, 1);
    if (vec_int(b, 0) < vec_int(a, 0))
    {
        pa(a, b, 1);
        pa(a, b, 1);
        return (1);
    }
    while(vec_int(b, 0) < vec_int(a, a->len - 1))
        rra(a, 1);
    pa(a, b, 1);
    while(vec_int(b, 0) < vec_int(a, a->len - 1) && vec_int(a, 0) > vec_int(a, a->len - 1))
        rra(a, 1);
    pa(a, b, 1);
    while(vec_int(a, 0) > vec_int(a, a->len - 1))
        rra(a, 1);
	return (1);
}

int	push_swap_medium(t_vec *a, t_vec *b)
{
	//push three to b, sort three, 
	//choose cheapest to push to b
	//push to b
	//loop until there are only three left in a
	//push them all back to a in an intelligent way
	//that will probably work.
	pb(a, b, 1);
	pb(a, b, 1);
	pb(a, b, 1);
	//print_vector(b);
	reverse_sort_three(b);
	while (a->len > 3)
	{
	//	ft_printf("about to enter choose_cheapest_push\n");
		//ft_printf("I SPY a zero:\n");
		//print_vector(a);
		//print_vector(b);

		choose_cheapest_push(a, b);
	}
	//now we need to sort a
	push_swap_three(a);
	batch_push(a, b);
	smart_rotate_a(a, find_min(a, find_max(a)));
	//now we need to push b back appropriately
	//print_vector(a);
	//print_vector(b);
	//ft_printf("Given the vectors a and b above, be believe the cheapest one is at index %d, which is %d\n", next, vec_int(a, next));
	

	//giving up on this logic for now, going to try a different approach
	/*int	max;
	int	min;
	int	midpoint;
	int index;
	int	init_len;
	int	below_midpoint;
	int i;

	below_midpoint = 0;
	index = 0;
	init_len = a->len;
	max = find_max(a);
	min = find_min(a, max);
	midpoint = min + ((max - min) / 2);
	while (i < a->len)
	{
		if (vec_int(a, i) < midpoint)
			below_midpoint++;
		i++;
	}
	i = 0;
	while )
	{
		if (vec_int(a, 0) < midpoint)
			pa(a, b, 1);
	}*/
	return (1);
}

int	push_swap(t_vec *a, t_vec *b)
{
	if (a->len == 1)
		return (1);
	else if (a->len < 4)
		push_swap_small(a);
	else if (a->len < 6)
		push_swap_five(a, b);
	else
		push_swap_medium(a, b);
	return (1);
}
//detect duplicate values and return an error
int	validate_input (t_vec *a)
{
	
	unsigned long i;
	i = 0;
	unsigned long k;
	k = 1;
	while (i < a->len - 1)
	{
		while (k < a->len)
		{
			if (vec_int(a, i) == vec_int(a, k))
				return (-1);
			k++;
		}
		i++;
		k = i + 1;
	}
	return (1);
	//detect values outside of integer range. except atoi is going to flunk this so I have to move this logic.
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
	if (validate_input(&a) == -1)
	{
		vec_free(&a);
		vec_free(&b);
		ft_putstr_fd("Error\n", 2);
		exit(-1);
	}
	if (check_order(&a) == 1)
	{
		vec_free(&a);
		vec_free(&b);
		exit(1);
	}
	push_swap(&a, &b);
	vec_free(&a);
	vec_free(&b);
}
