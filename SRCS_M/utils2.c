/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baouragh <baouragh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 18:05:57 by baouragh          #+#    #+#             */
/*   Updated: 2024/04/20 17:03:42 by baouragh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

int	set_range(t_list *stack_a)
{
	int	size;

	size = ft_lstsize(stack_a);
	if (size > 5 && size <= 16)
		return (3);
	else if (size <= 100)
		return (15);
	else if (size <= 500)
		return (30);
	else
		return (45);
}

void	put_max_rank(t_list **stack_a, t_list **stack_b, int pose, int max_rank)
{
	if (pose <= (ft_lstsize(*stack_b) / 2))
		while ((*stack_b)->rank != max_rank)
			rotate_b(stack_b, 1);
	else
		while ((*stack_b)->rank != max_rank)
			reverse_rotate_b(stack_b, 1);
	push_a(stack_a, stack_b, 1);
}

int	get_max_rank(t_list *stack_b)
{
	int	max_rank;

	if (!stack_b)
		return (0);
	max_rank = stack_b->rank;
	while (stack_b)
	{
		if (stack_b->rank > max_rank)
			max_rank = stack_b->rank;
		stack_b = stack_b->next;
	}
	return (max_rank);
}

bool	is_sorted(t_list *stack_a)
{
	if (!stack_a)
		return (0);
	if (!stack_a->next)
		return (1);
	while (stack_a)
	{
		if (stack_a->next && stack_a->rank > stack_a->next->rank)
			return (0);
		stack_a = stack_a->next;
	}
	return (1);
}

bool	check_revers(t_list *stack_a)
{
	while (stack_a)
	{
		if (stack_a->next && stack_a->rank < stack_a->next->rank)
			return (0);
		stack_a = stack_a->next;
	}
	return (1);
}
