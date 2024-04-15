/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baouragh <baouragh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 00:14:23 by baouragh          #+#    #+#             */
/*   Updated: 2024/04/15 21:10:18 by baouragh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

static	int	get_pose(t_list **stack_b, int rank)
{
	t_list	*tmp;
	int		pose;

	tmp = *stack_b;
	pose = 0;
	while (tmp)
	{
		if (tmp->rank == rank)
			return (pose);
		tmp = tmp->next;
		pose++;
	}
	return (pose);
}

static	void	to_stack_a(t_list **stack_a, t_list **stack_b)
{
	int	rank;

	while (*stack_b)
	{
		rank = get_rank(stack_b);
		put_max_rank(stack_a, stack_b, get_pose(stack_b, rank), rank);
	}
}

static	bool	check_revers(t_list *stack_a)
{
	while (stack_a)
	{
		if (stack_a->next && stack_a->rank < stack_a->next->rank)
			return (0);
		stack_a = stack_a->next;
	}
	return (1);
}

static	void	to_stack_b(t_list **stack_a, t_list **stack_b, int range, int i)
{
	while (*stack_a)
	{
		if ((*stack_a)->rank >= i && (*stack_a)->rank <= range + i)
		{
			push_b(stack_b, stack_a, 1);
			if ((*stack_b)->next && (*stack_b)->rank < (*stack_b)->next->rank)
				swap_b(stack_b, 1);
			i++;
		}
		else if ((*stack_a)->rank < i)
		{
			push_b(stack_b, stack_a, 1);
			rotate_b(stack_b, 1);
			i++;
		}
		else
		{
			if (check_revers(*stack_a))
				reverse_rotate_a(stack_a, 1);
			else
				rotate_a(stack_a, 1);
		}
	}
}

void	sort_three(t_list **stack_a)
{
	if ((*stack_a)->rank > (*stack_a)->next->rank)
	{
		if ((*stack_a)->next->rank > (*stack_a)->next->next->rank)
		{
			swap_a(stack_a, 1);
			reverse_rotate_a(stack_a, 1);
		}
		else if((*stack_a)->next->next->rank > (*stack_a)->rank)
			swap_a(stack_a, 1);
		else
			rotate_a(stack_a, 1);
	}
	else
	{
		if ((*stack_a)->next->next->rank > (*stack_a)->rank)
		{
			swap_a(stack_a, 1);
			rotate_a(stack_a, 1);
		}
		else
			reverse_rotate_a(stack_a, 1);
	}
}

void	short_algo(t_list **stack_a, t_list **stack_b)
{
	(void) stack_b;
	if (ft_lstsize(*stack_a) == 2)
		swap_a(stack_a, 1);
	else if (ft_lstsize(*stack_a) == 3)
		sort_three(stack_a);
	// else
	// 	sort_five(stack_a, stack_a);
}
bool	is_sorted(t_list *stack_a)
{
	if (!stack_a->next)
		return (1);
	while (stack_a)
	{
		if (stack_a->next && stack_a->rank > stack_a->next->rank)
			return (0);
		stack_a = stack_a->next;
	}
	return (1);
}
int	main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;
	int		i;
	int		range;

	stack_a = NULL;
	stack_b = NULL;
	if (argc == 1)
		return (1);
	i = 0;
	check_args(argv, &stack_a);
	if (is_sorted(stack_a))
		return (0);
	range = set_range(stack_a);
	if (ft_lstsize(stack_a) <= 5)
		short_algo(&stack_a, &stack_b);
	else
	{
		to_stack_b(&stack_a, &stack_b, range, i);
		to_stack_a(&stack_a, &stack_b);
	}
}
