/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pa.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baouragh <baouragh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 15:56:20 by baouragh          #+#    #+#             */
/*   Updated: 2024/04/13 17:31:15 by baouragh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"
// Take the first element at the top of b and put it at the top of a. 
// Do nothing if b is empty.
void    push_a(t_list **stack_a, t_list **stack_b, bool id)
{
    t_list *tmp;
    if (id)
        write(1,"pa\n",sizeof("pa\n"));
    if (!stack_b || !*stack_b)
        return;
    tmp = (*stack_b)->next; // save currnet next in b
    (*stack_b)->next = (*stack_a); // next will be head of a
    *stack_a = *stack_b; // set head of a last head of b 
    *stack_b = tmp; // set head of b the old next of old next head
}