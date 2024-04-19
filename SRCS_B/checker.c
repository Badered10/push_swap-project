/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baouragh <baouragh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 14:30:20 by baouragh          #+#    #+#             */
/*   Updated: 2024/04/19 18:08:32 by baouragh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

bool	is_opertion(char *str, t_list **stack_a, t_list **stack_b, int len)
{
	if (!ft_strncmp(str, "sa\n", len))
		swap_a(stack_a, 0);
	else if (!ft_strncmp(str, "sb\n", len))
		swap_b(stack_b, 0);
	else if (!ft_strncmp(str, "ss\n", len))
		swap_swap(stack_a, stack_b, 0);
	else if (!ft_strncmp(str, "pa\n", len))
		push_a(stack_a, stack_b, 0);
	else if (!ft_strncmp(str, "pb\n", len))
		push_b(stack_b, stack_a, 0);
	else if (!ft_strncmp(str, "ra\n", len))
		rotate_a(stack_a, 0);
	else if (!ft_strncmp(str, "rb\n", len))
		rotate_b(stack_b, 0);
	else if (!ft_strncmp(str, "rr\n", len))
		rotate_rotate(stack_a, stack_b, 0);
	else if (!ft_strncmp(str, "rra\n", len))
		reverse_rotate_a(stack_a, 0);
	else if (!ft_strncmp(str, "rrb\n", len))
		reverse_rotate_b(stack_b, 0);
	else if (!ft_strncmp(str, "rrr\n", len))
		reverse_rr(stack_a, stack_b, 0);
	else
		return (write(2, "Error\n", 6), 0);
	return (1);
}

void	apply_operations(t_list **stack_a, t_list **stack_b)
{
	char	*str;
	int		len;

	str = NULL;
	str = get_next_line(0);
	while (str)
	{
		len = ft_strlen(str);
		if (len > 4 || len < 3)
		{
			write(2, "Error\n", 6);
			exit(1);
		}
		if (is_opertion(str, stack_a, stack_b, len))
			;
		else
			exit(1);
		free(str);
		str = get_next_line(0);
	}
}

int	main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (argc == 1)
		return (0);
	check_args(argv, &stack_a);
	apply_operations(&stack_a, &stack_b);
	if (is_sorted(stack_a) && !stack_b)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	return (0);
}
