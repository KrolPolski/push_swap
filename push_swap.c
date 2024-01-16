/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rboudwin <rboudwin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 15:17:15 by rboudwin          #+#    #+#             */
/*   Updated: 2024/01/16 11:13:17 by rboudwin         ###   ########.fr       */
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
	long	tmp;
	int		int_tmp;
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
		//this logic is breaking negative numbers
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
		//ft_printf("%d, ", *ptr);
		i++;
	}
	return (1);
}
int	reverse_sort_three(t_vec *b)
{
	if (vec_int(b, 0) > vec_int(b, 1) && vec_int(b, 2) > vec_int(b, 0))
	{
		rrb(b, 1);
		return (1);
	}
	else if (vec_int(b, 0) < vec_int(b, 1) && vec_int(b, 2) < vec_int(b, 0))
	{
		sb(b, 1);
		return (1);
	}
	else if (vec_int(b, 1) < vec_int(b, 2) && vec_int(b, 0) > vec_int(b, 2))
	{
		rrb(b, 1);
		sb(b, 1);
		return (1);
	}
	else if (vec_int(b, 0) > vec_int(b, 1) && vec_int(b, 1) > vec_int(b, 2))
	{
		return (1);
	}
	else if (vec_int(b, 0) > vec_int(b, 1) && vec_int(b, 2) > vec_int(b, 0))
	{
	    rrb(b, 1);
		return (1);
	}
	else if (vec_int(b, 0) < vec_int(b, 1) && vec_int(b,1) < vec_int(b, 2))
	{
		rb(b, 1);
		sb(b, 1);
	}
//	else
//		ft_printf("Something went wrong in push_swap_three");
	return (-1);
}

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
//	else
//		ft_printf("Something went wrong in push_swap_three");
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
/* make an answer key. problem solved
1. check first three cards to see if they should be adjacent. 
if so ra 3, 2, or 1 times as required to get to three cards that don't belong together. if not do nothing
2. push three cards
3. calculate the shortest path to an insertion point. rotate or swap as needed to get the right card on top of b.
4. smart rotate to insertion point (integer just above top card of b), then push a, repeat until all the cards are gone
5. smart rotate to the next card that is not adjacent to where it should be. 
6. push. repeat 5 until there are three cards in b. then go to 3. loop this until it matches the sorted set.*/

/*to implement the above, we need 1) an answer key, 
2) a function that will check the distance of every vector item
from its intended insertion point so we can choose the lowest cost options */
//that is a start.
/*ALT: 1. push 2
		2. calculate rotation distance in a to the first integer above b, 0 and b,1
		3. if b, 0 distance <= b, 1, smart rotate, then push a, otherwise swap b and then do it
		3. if the second card in b belongs in the next spot, push it now
		3. if one of them is the max, distance to min instead.
		4. rra and swap until you can't solve it
		5. smart rotate and insert 2nd card from b
		6. rra and swap until you can't. then push b. 
		7. rra and swap until you can't then push b.
		8. go to 3. until it is sorted
		
		/* 1. push the first two cards no matter what
   2. swap or double swap if needed to ensure low card on top of a, high card on top of b
   3. if the next a card is higher than top card of b, push it until that isn't true
   4. smart rotate a to a_min
   5. while b, 0 > than bottom of A ,push a
   6. rra 
   7. swap if needed until top of a > 2nd card in a but also > 3rd card.
   8. push b.
   9. if top of b < max of a, smart rotate to max
   10. if top of b < max of a but also more than bottom of a, push a, else rra
   11. if b, 0 < a, 0 and greater than the bottom one, push a, else rra, swap as needed until you can't, then push b
   12. identify the integer just above the integer in b. smart rotate to that, push a
   13. once we are out of stuff in b, smart rotate to min, be done */
int	push_swap_five(t_vec *a, t_vec *b)
{
	pb(a, b, 1);
	pb(a, b, 1);	
	push_swap_small(a, b);
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
	int	next;
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
	else if (a->len < 4)
		push_swap_small(a, b);
	else if (a->len < 6)
		push_swap_five(a, b);
	else
		push_swap_medium(a, b);
	/*
	if (a->len < 100)
		push_swap_large(a, b);
	if (a->len >= 100)
		push_swap_jumbo(a, b);*/
	return (1);
}
int	validate_input (t_vec *a)
{
	//detect duplicate values
	int i;
	i = 0;
	int k;
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
	//we have to add logic to catch duplicate values and error out DONE
	//also we need to catch anything outside the integer range and error out as well DONE
	//went from five to a hundred, then to 500;
	//probably need to push to b until there are only three left in a, using smart rotates
	//to keep them in order.
	//need a cost comparison feature to decide which thing we have to get to first.
	//fix header emails on each of the libft things that got borked by VSCode
	int ret;
	t_vec a;
	t_vec b;
	t_vec key;

	if (argc < 2)
	{
		ft_putstr_fd("Error\n", 2);
		exit(-1);
	}
	vec_new(&a, 0, sizeof(int));
	vec_new(&b, 0, sizeof(int));
	ret = convert_and_build_vector(&a, argc, argv);
	//vec_from(&key, &a, a.len, a.elem_size);
	//vec_sort(&key, ft_memcmp);
	//print_vector(&a);
	//smart_rotate(&a, 5);
	//print_vector(&a);
	if (ret == -1)
	{
		ft_putstr_fd("Error\n", 2);
	//	ft_printf("We concluded that convert and build vector failed\n");
		exit(-1);
	}
	if (validate_input(&a) == -1)
	{
		vec_free(&a);
		vec_free(&b);
		ft_putstr_fd("Error\n", 2);
	//	ft_printf("we concluded that validate_input failed\n");
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
