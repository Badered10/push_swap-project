/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baouragh <baouragh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 00:40:25 by baouragh          #+#    #+#             */
/*   Updated: 2024/04/18 19:03:28 by baouragh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "ft_printf.h"

void	swap_a(t_list **stack_a, bool id);
void	swap_b(t_list **stack_b, bool id);
void	push_a(t_list **stack_a, t_list **stack_b, bool id);
void	push_b(t_list **stack_b, t_list **stack_a, bool id);
void	swap_swap(t_list **stack_a, t_list **stack_b, bool id);
void	rotate_a(t_list **stack_a, bool id);
void	rotate_b(t_list **stack_b, bool id);
void	rotate_rotate(t_list **stack_a, t_list **stack_b, bool id);
void	reverse_rotate_a(t_list **stack_a, bool id);
void	reverse_rotate_b(t_list **stack_b, bool id);
void	reverse_rr(t_list **stack_a, t_list **stack_b, bool id);
void	check_args(char **argv, t_list **list);
void	free_double(char **ptr);
void	del(void *ptr);
long	ft_atol(char *var, long res, long signe);
bool	check_duplicate(t_list *list, long number);
int		set_range(t_list *stack_a);
void	put_max_rank(t_list **stack_a, t_list **stack_b, int pose, int rank);
int		get_max_rank(t_list *stack_b);
int		get_pose(t_list *stack_b, int rank);
bool	is_sorted(t_list *stack_a);
bool	check_revers(t_list *stack_a);
void	push_by_rank(t_list **stack_a, t_list **stack_b, int rank, int size);
void	sort_three(t_list **stack_a);

#endif