/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pb.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baouragh <baouragh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 17:05:45 by baouragh          #+#    #+#             */
/*   Updated: 2024/04/21 18:04:38 by baouragh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap_bonus.h"

/*
	push b): Take the first element at the top of a and put it at the top of b.
	Do nothing if a is empty
*/
void	push_b(t_list **stack_b, t_list **stack_a, bool id)
{
	t_list	*tmp;

	if (!stack_a || !*stack_a)
		return ;
	tmp = (*stack_a)->next;
	ft_lstadd_front(stack_b, *stack_a);
	*stack_a = tmp;
	if (id)
		ft_printf("pb\n");
}
