/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baouragh <baouragh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 01:04:47 by baouragh          #+#    #+#             */
/*   Updated: 2024/04/12 15:22:20 by baouragh         ###   ########.fr       */
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

long	ft_atol(const char *str)
{
	char	*var;
	long	res;
	int		signe;

	var = (char *)str;
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
	if (*x > 2147483647 || *x < -2147483648 || !check_duplicate(*list, *x))
		return (free(x), NULL);
	node = ft_lstnew(x);
	if (!node)
		return (free(x), NULL);
	return (node);
}

bool	check_whole(char *argv)
{
	while (*argv)
	{
		if (!ft_isdigit(*argv) && *argv != ' ' && *argv != '+' && *argv != '-')
			return (0);
		argv++;
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

	i = 1;
	while (argv[i])
	{
		check = check_whole(argv[i]);
		if (!check)
			return (ft_putstr_fd("Error\n", 2), ft_lstclear(list, del));
		split_and_check(i, argv, list);
		i++;
	}
}

int	main(int argc, char **argv)
{
	t_list	*list;
	t_list	*save;

	if (argc == 1)
		return (1);
	check_args(argv, &list);
	save = list;
	while (list)
	{
		ft_printf("From --> '%p' and ", list);
		ft_printf("value --> '%d'\n", *(int *)list->content);
		list = list->next;
	}
	ft_lstclear(&save, del);
	system("leaks push_swap");
}
