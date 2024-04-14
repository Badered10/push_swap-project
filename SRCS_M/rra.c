/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rra.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baouragh <baouragh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 18:26:20 by baouragh          #+#    #+#             */
/*   Updated: 2024/04/14 13:28:47 by baouragh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

/*
    rra (reverse rotate a): Shift down all elements of stack a by 1.
    The last element becomes the first one.
*/

t_list *before_last(t_list *list)
{
    t_list *tmp;
    int size;

    size = ft_lstsize(list);
    while (size-- > 0)
    {
        if(list->next)
            list = list->next;
        if(list->next)
            tmp = list;
    }
    return (tmp);
}

void reverse_rotate_a(t_list **stack_a, bool id)
{
    t_list *before;
    t_list *last;

    if (!stack_a || !*stack_a || !(*stack_a)->next)
        return;
    last = ft_lstlast(*stack_a);
    before = before_last(*stack_a);
    last->next = *stack_a;
    before->next = NULL;
    *stack_a = last;
    if (id)
        write(1, "rra\n", sizeof("rra\n"));
}