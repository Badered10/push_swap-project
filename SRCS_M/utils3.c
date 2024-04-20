/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baouragh <baouragh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 18:58:52 by baouragh          #+#    #+#             */
/*   Updated: 2024/04/20 17:03:15 by baouragh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

void	push_by_rank(t_list **stack_a, t_list **stack_b, int rank)
{
	int	pose;
	int	size;

	size = ft_lstsize(*stack_a);
	pose = get_pose(*stack_a, rank);
	if (pose <= (size / 2))
		while ((*stack_a)->rank != rank)
			rotate_a(stack_a, 1);
	else
		while ((*stack_a)->rank != rank)
			reverse_rotate_a(stack_a, 1);
	push_b(stack_b, stack_a, 1);
}

void	sort_three(t_list **stack_a)
{
	if ((*stack_a)->rank > (*stack_a)->next->rank)
	{
		if ((*stack_a)->next->rank > (*stack_a)->next->next->rank)
		{
			swap_a(stack_a, 1);
			reverse_rotate_a(stack_a, 1);
		}
		else if ((*stack_a)->next->next->rank > (*stack_a)->rank)
			swap_a(stack_a, 1);
		else
			rotate_a(stack_a, 1);
	}
	else if ((*stack_a)->rank < (*stack_a)->next->rank
		&& (*stack_a)->next->next->rank < (*stack_a)->next->rank)
	{
		if ((*stack_a)->next->next->rank > (*stack_a)->rank)
		{
			swap_a(stack_a, 1);
			rotate_a(stack_a, 1);
		}
		else
			reverse_rotate_a(stack_a, 1);
	}
}
