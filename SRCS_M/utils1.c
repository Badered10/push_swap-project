/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baouragh <baouragh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 18:05:48 by baouragh          #+#    #+#             */
/*   Updated: 2024/04/18 21:03:34 by baouragh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

long	ft_atol(char *var, long res, long signe)
{
	while ((*var >= 9 && *var <= 13) || *var == 32)
		var++;
	if (*var == '-' || *var == '+')
	{
		if (*var == '-')
			signe *= -1;
		var++;
	}
	if (!*var)
		return (2147483648);
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

int	get_pose(t_list *stack_b, int rank)
{
	int		pose;

	pose = 0;
	while (stack_b)
	{
		if (stack_b->rank == rank)
			return (pose);
		stack_b = stack_b->next;
		pose++;
	}
	return (pose);
}
