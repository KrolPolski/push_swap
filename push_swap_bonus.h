/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rboudwin <rboudwin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 16:03:16 by rboudwin          #+#    #+#             */
/*   Updated: 2024/01/29 16:05:54 by rboudwin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H
# include "push_swap.h"

int		checker(t_vec *a, t_vec *b);
void	execute_orders(t_vec *a, t_vec *b, char *str);
int		process_single_order(t_vec *a, t_vec *b, char *str);
int		checker_order(t_vec *a, t_vec *b);
void	detect_duplicates(t_vec *a, t_vec *b);
#endif