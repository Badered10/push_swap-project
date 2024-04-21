/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrb.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baouragh <baouragh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 14:39:42 by baouragh          #+#    #+#             */
/*   Updated: 2024/04/21 18:04:38 by baouragh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap_bonus.h"

static t_list	*before_last(t_list *list)
{
	t_list	*tmp;
	int		size;

	size = ft_lstsize(list);
	while (size-- > 0)
	{
		if (list->next)
			list = list->next;
		if (list->next)
			tmp = list;
	}
	return (tmp);
}

/*
   (reverse rotate b): Shift down all elements of stack b by 1.
	The last element becomes the first one.
*/
void	reverse_rotate_b(t_list **stack_b, bool id)
{
	t_list	*before;
	t_list	*last;

	if (!stack_b || !*stack_b || !(*stack_b)->next)
		return ;
	last = ft_lstlast(*stack_b);
	before = before_last(*stack_b);
	last->next = *stack_b;
	before->next = NULL;
	*stack_b = last;
	if (id)
		ft_printf("rrb\n");
}
