/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sa.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baouragh <baouragh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 23:37:13 by baouragh          #+#    #+#             */
/*   Updated: 2024/03/23 01:28:07 by baouragh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

void	swap_a(t_list **stack_a, bool id)
{
	t_list	*next_node;

	if (!stack_a || !(*stack_a) || !(*stack_a)->next)
		return ;
	next_node = (*stack_a);
	next_node = next_node->next;
	swap((*stack_a)->content, next_node->content);
	if (id)
		ft_printf("sa\n");
}
/*
		int main()
	{
		t_list *node;
		t_list *node1;
		t_list *node2;

		int a;
		int b;
		int c;

		a = 10;
		b = 2;
		c = 3;

		node = ft_lstnew(&a);
		node1 = ft_lstnew(&b);
		node2 = ft_lstnew(&c);

		node->next = node1;
		node1->next = node2;

		printf("node a :%d\n",*(int*)node->content);
		printf("node b :%d\n",*(int*)node1->content);

		swap_a(&node);

		printf("after swap a with b\n");
		printf("node a :%d\n",*(int*)node->content);
		printf("node b :%d\n",*(int*)node1->content);
	}
*/
