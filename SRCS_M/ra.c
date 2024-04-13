/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ra.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baouragh <baouragh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 17:12:58 by baouragh          #+#    #+#             */
/*   Updated: 2024/04/13 17:42:55 by baouragh         ###   ########.fr       */
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

    if (id)
        write(1,"ra\n",sizeof("ra\n"));
    if (!stack_a || !*stack_a || !(*stack_a)->next)
        return;
    tmp = ft_lstlast(*stack_a);
    tmp->next = *stack_a;
    tmp = (*stack_a)->next;
    (*stack_a)->next = NULL;
    (*stack_a) = tmp;
}
