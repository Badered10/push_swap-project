/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sa.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baouragh <baouragh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 23:37:13 by baouragh          #+#    #+#             */
/*   Updated: 2024/04/14 12:14:04 by baouragh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"


void	swap_a(t_list **stack_a, bool id)
{
	t_list *second_node;
	t_list *second_next;

	if (!stack_a || !(*stack_a) || !(*stack_a)->next)
		return ;
	second_node = (*stack_a)->next;
	second_next = second_node->next;
	(*stack_a)->next = second_next;
	second_node->next = *(stack_a);
	*stack_a = second_node;
	if (id)
		write(1,"sa\n",sizeof("sa\n"));
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
