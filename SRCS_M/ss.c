/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ss.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baouragh <baouragh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 00:47:12 by baouragh          #+#    #+#             */
/*   Updated: 2024/04/14 12:31:19 by baouragh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

void	swap_swap(t_list **stack_a, t_list **stack_b, bool id)
{
	swap_a(stack_a, 0);
	swap_b(stack_b, 0);
	if (id)
		write(1,"ss\n",sizeof("ss\n"));
}
