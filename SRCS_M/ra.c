/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ra.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baouragh <baouragh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 17:12:58 by baouragh          #+#    #+#             */
/*   Updated: 2024/04/14 11:54:03 by baouragh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"
/*
    Shift up all elements of stack a by 1.
    The first element becomes the last one.
*/
void rotate_a(t_list **stack_a, bool id)
{
    t_list *tmp;

    if (!stack_a || !*stack_a || !(*stack_a)->next)
        return;
    tmp = (*stack_a)->next;
    ft_lstadd_back(stack_a, *stack_a);
    *stack_a = tmp;
    if (id)
        write(1,"ra\n",sizeof("ra\n"));
}
