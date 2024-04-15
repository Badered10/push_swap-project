/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sa.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baouragh <baouragh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 23:37:13 by baouragh          #+#    #+#             */
/*   Updated: 2024/04/15 17:01:07 by baouragh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

/*
	(swap a): Swap the first 2 elements at the top of stack a.
	Do nothing if there is only one or no elements.
*/
void	swap_a(t_list **stack_a, bool id)
{
	t_list	*second_node;
	t_list	*second_next;

	if (!stack_a || !(*stack_a) || !(*stack_a)->next)
		return ;
	second_node = (*stack_a)->next;
	second_next = second_node->next;
	(*stack_a)->next = second_next;
	second_node->next = *(stack_a);
	*stack_a = second_node;
	if (id)
		ft_printf("sa\n");
}
