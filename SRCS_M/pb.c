/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pb.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baouragh <baouragh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 17:05:45 by baouragh          #+#    #+#             */
/*   Updated: 2024/04/13 17:31:45 by baouragh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"
// Take the first element at the top of b and put it at the top of a. 
// Do nothing if b is empty.
void    push_b(t_list **stack_b, t_list **stack_a, bool id)
{
    t_list *tmp;
    if (id)
        write(1,"pb\n",sizeof("pb\n"));
    if (!stack_a || !*stack_a)
        return;
    tmp = (*stack_a)->next; // save currnet next in a
    (*stack_a)->next = (*stack_b); // next will be head of b
    *stack_b = *stack_a; // set head of b last head of a 
    *stack_a = tmp; // set head of a the old next of old next head
}