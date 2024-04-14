/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rra.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baouragh <baouragh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 18:26:20 by baouragh          #+#    #+#             */
/*   Updated: 2024/04/14 11:28:01 by baouragh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

/*
    rra (reverse rotate a): Shift down all elements of stack a by 1.
    The last element becomes the first one.
*/

void reverse_rotate_a(t_list **stack_a, bool id)
{
    t_list *tmp;

    if (!stack_a || !*stack_a || !(*stack_a)->next)
        return;
    tmp = ft_lstlast(*stack_a);
    if (id)
        write(1, "rra\n", sizeof("rra\n"));
}