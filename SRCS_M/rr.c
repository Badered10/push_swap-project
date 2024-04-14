/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rr.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baouragh <baouragh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 17:47:52 by baouragh          #+#    #+#             */
/*   Updated: 2024/04/14 11:27:56 by baouragh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

/*
    rr : ra and rb at the same time.
*/

void rotate_rotate(t_list **stack_a, t_list **stack_b, bool id)
{
    rotate_a(stack_a, 0);
    rotate_b(stack_b, 0);
    if (id)
        write(1, "rr\n", sizeof("rr\n"));
}
