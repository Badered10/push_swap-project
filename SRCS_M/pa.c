/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pa.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baouragh <baouragh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 15:56:20 by baouragh          #+#    #+#             */
/*   Updated: 2024/04/14 11:49:00 by baouragh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

void    push_a(t_list **stack_a, t_list **stack_b, bool id)
{
    t_list *tmp;

    if (!stack_b || !*stack_b)
        return;
    tmp = (*stack_b)->next;
    ft_lstadd_front(stack_a, *stack_b);
    *stack_b = tmp;
    if (id)
        write(1,"pa\n",sizeof("pa\n"));
}
