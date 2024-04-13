/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sb.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baouragh <baouragh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 00:44:06 by baouragh          #+#    #+#             */
/*   Updated: 2024/04/13 17:32:19 by baouragh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

void	swap_b(t_list **stack_b, bool id)
{
	t_list	*next_node;

	if (id)
		write(1,"sb\n",sizeof("sb\n"));
	if (!stack_b || !(*stack_b) || !(*stack_b)->next)
		return ;
	next_node = (*stack_b);
	next_node = next_node->next;
	swap((*stack_b)->content, next_node->content);
}
