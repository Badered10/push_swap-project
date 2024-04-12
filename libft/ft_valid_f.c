/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_f.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baouragh <baouragh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 15:58:18 by baouragh          #+#    #+#             */
/*   Updated: 2024/02/28 16:31:48 by baouragh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/libft.h"

static int	check_first(char **str, int *signe, int *before_p) //2. --> 
{
	if (*(*str) == '+' || *(*str) == '-')
	{
		if (*(*str) == '-')
			*signe = -1;
		(*str)++;
	}
	if (ft_isdigit(*(*str)))
		*before_p = ft_atoi((*str));
	else
		return (3);
	if (*before_p > 2 || *before_p < -2)
		return (3);
	while (ft_isdigit(*(*str)))
		(*str)++;
	if (*(*str) == '.')
	{
		(*str)++;
		if (!*(*str))
			return (3);
	}
	return (0);
}

static double	check_last(char **str, int *before_p, int *time, double *res)
{
	while (ft_isdigit(*(*str)))
	{
		*res = *res + (*(*str) - 48) * 0.1 / *time;
		(*str)++;
		*time *= 10;
	}
	if (*(*str) == '\0')
	{
		*res += (*before_p);
		if (*res > 2 || *res < -2)
			return (3);
		return (*res);
	}
	else
		return (3);
}

double	valid_f(char *str)
{
	double	res;
	int		before_p;
	int		time;
	int		signe;

	signe = 1;
	time = 1;
	res = 0;
	before_p = 0;
	if (check_first(&str, &signe, &before_p) == 3)
		return (3);
	if (!*str)
		return (before_p * signe);
	else if (!ft_isdigit(*str))
		return (3);
	if (check_last(&str, &before_p, &time, &res) == 3)
		return (3);
	return (res * signe);
}
