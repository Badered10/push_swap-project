/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baouragh <baouragh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 01:04:47 by baouragh          #+#    #+#             */
/*   Updated: 2024/04/15 21:35:23 by baouragh         ###   ########.fr       */
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

static	t_list	*get_number(char *argv, t_list **list)
{
	t_list	*node;
	long	*x;
	long	res;
	long	signe;

	signe = 1;
	res = 0;
	x = malloc(sizeof(long));
	if (!x)
		return (NULL);
	*x = ft_atol(argv, res, signe);
	if (*x == 2147483648 || !check_duplicate(*list, *x))
		return (free(x), NULL);
	node = ft_lstnew(x);
	if (!node)
		return (free(x), NULL);
	return (node);
}

static	bool	check_whole(char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (argv[i])
	{
		j = 0;
		while (argv[i][j])
		{
			if (!ft_isdigit(argv[i][j]) && argv[i][j] != ' '
				&& argv[i][j] != '+' && argv[i][j] != '-')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

static void	set_rank(t_list *list, t_list *node)
{
	node->rank = 0;
	if (!list)
		return ;
	while (list)
	{
		if (*(int *)list->content < *(int *)node->content)
			node->rank++;
		else if (*(int *)list->content > *(int *)node->content)
			list->rank++;
		list = list->next;
	}
}

static	void	split_and_check(int j, int i, char **argv, t_list **list)
{
	t_list	*node;
	char	**args;

	args = ft_split(argv[i], ' ');
	if (!args || !*args)
		return (ft_putstr_fd("Error\n", 2), ft_lstclear(list, del),
			free_double(args), exit(1));
	while (args[j])
	{
		node = get_number(args[j], list);
		if (!node)
		{
			return (ft_putstr_fd("Error\n", 2), ft_lstclear(list, del),
				free_double(args), exit(1));
		}
		if (i == 1 && !j)
			*list = node;
		set_rank(*list, node);
		ft_lstadd_back(list, node);
		j++;
	}
	free_double(args);
}

void	check_args(char **argv, t_list **list)
{
	int		i;
	int		j;
	bool	check;

	check = check_whole(argv);
	if (!check)
	{
		ft_putstr_fd("Error\n", 2);
		exit(1);
	}
	i = 1;
	while (argv[i])
	{
		j = 0;
		split_and_check(j, i, argv, list);
		i++;
	}
}
