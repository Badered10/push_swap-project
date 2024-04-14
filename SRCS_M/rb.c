/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rb.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baouragh <baouragh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 17:45:11 by baouragh          #+#    #+#             */
/*   Updated: 2024/04/14 11:54:44 by baouragh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"
/*
    Shift up all elements of stack a by 1.
    The first element becomes the last one.
*/
void rotate_b(t_list **stack_b, bool id)
{
    t_list *tmp;

    if (!stack_b || !*stack_b || !(*stack_b)->next)
        return;
    tmp = (*stack_b)->next;
    ft_lstadd_back(stack_b, *stack_b);
    *stack_b = tmp;
    if (id)
        write(1,"rb\n",sizeof("rb\n"));
}