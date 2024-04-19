/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baouragh <baouragh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 16:29:17 by baouragh          #+#    #+#             */
/*   Updated: 2024/04/19 18:21:57 by baouragh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

bool	is_sorted(t_list *stack_a)
{
	if(!stack_a)
		return (0);
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
