/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pb.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baouragh <baouragh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 17:05:45 by baouragh          #+#    #+#             */
/*   Updated: 2024/04/14 11:48:54 by baouragh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

void    push_b(t_list **stack_b, t_list **stack_a, bool id)
{
    t_list *tmp;

    if (!stack_a || !*stack_a)
        return;
    tmp = (*stack_a)->next;
    ft_lstadd_front(stack_b, *stack_a);
    *stack_a = tmp;
    if (id)
        write(1,"pb\n",sizeof("pb\n"));
}