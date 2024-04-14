/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sb.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baouragh <baouragh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 00:44:06 by baouragh          #+#    #+#             */
/*   Updated: 2024/04/14 12:15:00 by baouragh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

void	swap_b(t_list **stack_b, bool id)
{
	t_list *second_node;
	t_list *second_next;

	if (!stack_b || !(*stack_b) || !(*stack_b)->next)
		return ;
	second_node = (*stack_b)->next;
	second_next = second_node->next;
	(*stack_b)->next = second_next;
	second_node->next = *(stack_b);
	*stack_b = second_node;
	if (id)
		write(1,"sb\n",sizeof("sb\n"));
}
