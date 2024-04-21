/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sb.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baouragh <baouragh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 00:44:06 by baouragh          #+#    #+#             */
/*   Updated: 2024/04/21 18:04:38 by baouragh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap_bonus.h"

/*
	(swap b): Swap the first 2 elements at the top of stack b.
	Do nothing if there is only one or no elements.
*/
void	swap_b(t_list **stack_b, bool id)
{
	t_list	*second_node;
	t_list	*second_next;

	if (!stack_b || !(*stack_b) || !(*stack_b)->next)
		return ;
	second_node = (*stack_b)->next;
	second_next = second_node->next;
	(*stack_b)->next = second_next;
	second_node->next = *(stack_b);
	*stack_b = second_node;
	if (id)
		ft_printf("sb\n");
}
