/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pa.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baouragh <baouragh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 15:56:20 by baouragh          #+#    #+#             */
/*   Updated: 2024/04/21 18:04:38 by baouragh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap_bonus.h"

/*
	(push a): Take the first element at the top of b and put it at the top of a.
	Do nothing if b is empty.
*/
void	push_a(t_list **stack_a, t_list **stack_b, bool id)
{
	t_list	*tmp;

	if (!stack_b || !*stack_b)
		return ;
	tmp = (*stack_b)->next;
	ft_lstadd_front(stack_a, *stack_b);
	*stack_b = tmp;
	if (id)
		ft_printf("pa\n");
}
