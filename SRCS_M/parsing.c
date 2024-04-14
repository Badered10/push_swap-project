/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baouragh <baouragh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 01:04:47 by baouragh          #+#    #+#             */
/*   Updated: 2024/04/14 12:32:52 by baouragh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"
#include <ctype.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

ssize_t	ft_atol(char *var)
{
	ssize_t	res;
	ssize_t	signe;

	res = 0;
	signe = 1;
	while ((*var >= 9 && *var <= 13) || *var == 32)
		var++;
	if (*var == '-' || *var == '+')
	{
		if (*var == '-')
			signe *= -1;
		var++;
	}
	while (*var && *var >= '0' && *var <= '9')
	{
		res = res * 10 + (*var - '0');
		if (res * signe > 2147483647 || res * signe < -2147483648)
			return (2147483648);
		var++;
	}
	res *= signe;
	if (*var)
		return (2147483648);
	return (res);
}

void	del(void *ptr)
{
	if (ptr)
		free(ptr);
}

void	free_double(char **ptr)
{
	int	i;

	i = 0;
	if (!ptr)
		return ;
	while (ptr[i])
	{
		free(ptr[i]);
		i++;
	}
	free(ptr);
}

bool	check_duplicate(t_list *list, long number)
{
	while (list)
	{
		if (number != *(int *)(list)->content)
			list = (list)->next;
		else
			return (0);
	}
	return (1);
}

t_list	*get_number(char *argv, t_list **list)
{
	t_list	*node;
	long	*x;

	(void)list;
	x = malloc(sizeof(long));
	if (!x)
		return (NULL);
	*x = ft_atol(argv);
	if (*x == 2147483648 || !check_duplicate(*list, *x))
		return (free(x), NULL);
	node = ft_lstnew(x);
	if (!node)
		return (free(x), NULL);
	return (node);
}

bool	check_whole(char **argv)
{
	int i;
	int j;

	i = 1;
	while (argv[i])
	{
		j = 0;
		while(argv[i][j])
		{
			if (!ft_isdigit(argv[i][j]) && argv[i][j] != ' ' && argv[i][j] != '+' && argv[i][j] != '-')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

void	split_and_check(int i, char **argv, t_list **list)
{
	t_list	*node;
	char	**args;
	int		j;

	j = 0;
	args = ft_split(argv[i], ' ');
	while (args[j])
	{
		node = get_number(args[j], list);
		if (!node)
			return (ft_putstr_fd("Error\n", 2), ft_lstclear(list, del),
				free_double(args));
		if (i == 1 && !j)
			*list = node;
		ft_lstadd_back(list, node);
		j++;
	}
	free_double(args);
}

void	check_args(char **argv, t_list **list)
{
	int		i;
	bool	check;

	check = check_whole(argv);
	if (!check)
		return ((void)ft_putstr_fd("Error whole\n", 2));
	i = 1;
	while (argv[i])
	{
		split_and_check(i, argv, list);
		i++;
	}
}

int	main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;
	t_list	*save;

	if (argc == 1)
		return (1);
	check_args(argv, &stack_a);
	save = stack_a;
	stack_b = NULL;
	
	// swap_a(&stack_a,1);
	// swap_a(&stack_a,1);
	push_b(&stack_b,&stack_a,1);
	push_b(&stack_b,&stack_a,1);
	push_b(&stack_b,&stack_a,1);
	// swap_b(&stack_b,1);
	// swap_a(&stack_a,1);
	swap_swap(&stack_a, &stack_b, 1);
	// push_b(&stack_b,&stack_a,1);
	// rotate_rotate(&stack_a, &stack_b,1);
	// rotate_a(&stack_a,1);
	// rotate_a(&stack_a,1);
	// rotate_a(&stack_a,1);
	while (stack_a)
	{
		ft_printf("a From --> '%p' and ", stack_a);
		ft_printf("value --> '%d'\n", *(int *)stack_a->content);
		stack_a = stack_a->next;
	}
	while (stack_b)
	{
		ft_printf("b From --> '%p' and ", stack_b);
		ft_printf("value --> '%d'\n", *(int *)stack_b->content);
		stack_b = stack_b->next;
	}
	ft_lstclear(&save, del);
	// system("leaks push_swap");
}
