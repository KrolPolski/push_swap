/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rboudwin <rboudwin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 13:15:33 by rboudwin          #+#    #+#             */
/*   Updated: 2023/12/28 14:52:56 by rboudwin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*	The plan:
	1. Decide on data types. Do arrays make sense here? Or do I need a vector?
	2. Convert argv to integers
	3. handle invalid arguments, not enough arguments, etc.
	4. Write a function for each push_swap instruction
	5. Write logic to decide how to choose which instruction for what situation
*/
int	main(int argc, char **argv)
{
	t_list	a;
	t_list	b;

	if (argc < 2)
		ft_putstr_fd("Error\n", 2);
}