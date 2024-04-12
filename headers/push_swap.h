/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baouragh <baouragh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 00:40:25 by baouragh          #+#    #+#             */
/*   Updated: 2024/04/12 15:16:52 by baouragh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "ft_printf.h"

void	swap(int *a, int *b);
void	swap_a(t_list **list, bool id);
void	swap_b(t_list **list, bool id);
void	swap_swap(t_list **stack_a, t_list **stack_b, bool id);

#endif