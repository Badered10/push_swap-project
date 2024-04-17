/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baouragh <baouragh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 18:05:57 by baouragh          #+#    #+#             */
/*   Updated: 2024/04/15 21:32:16 by baouragh         ###   ########.fr       */
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

void	put_max_rank(t_list **stack_a, t_list **stack_b, int pose, int rank)
{
	if (pose <= (ft_lstsize(*stack_b) / 2))
	{
		while ((*stack_b)->rank != rank)
			rotate_b(stack_b, 1);
	}
	else
	{
		while ((*stack_b)->rank != rank)
			reverse_rotate_b(stack_b, 1);
	}
	push_a(stack_a, stack_b, 1);
}

int	get_rank(t_list *stack_b)
{
	int		rank;

	rank = stack_b->rank;
	while (stack_b)
	{
		if (stack_b->rank > rank)
			rank = stack_b->rank;
		stack_b = stack_b->next;
	}
	return (rank);
}
