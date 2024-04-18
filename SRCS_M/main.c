/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baouragh <baouragh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 00:14:23 by baouragh          #+#    #+#             */
/*   Updated: 2024/04/18 20:52:01 by baouragh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

static	void	to_stack_a(t_list **stack_a, t_list **stack_b)
{
	int	max_rank;

	while (*stack_b)
	{
		max_rank = get_max_rank(*stack_b);
		put_max_rank(stack_a, stack_b, get_pose(*stack_b, max_rank), max_rank);
	}
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

static	void	sort_five(t_list **stack_a, t_list **stack_b)
{
	int	size;

	size = ft_lstsize(*stack_a);
	push_by_rank(stack_a, stack_b, 0);
	if (size == 5)
		push_by_rank(stack_a, stack_b, 1);
	sort_three(stack_a);
	push_a(stack_a, stack_b, 1);
	if (size == 5)
		push_a(stack_a, stack_b, 1);
}

static	void	short_algo(t_list **stack_a, t_list **stack_b)
{
	if (ft_lstsize(*stack_a) == 2)
		swap_a(stack_a, 1);
	else if (ft_lstsize(*stack_a) == 3)
		sort_three(stack_a);
	else
		sort_five(stack_a, stack_b);
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
