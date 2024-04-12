/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnstr_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baouragh <baouragh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 08:23:07 by baouragh          #+#    #+#             */
/*   Updated: 2024/03/23 01:34:26 by baouragh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/libft.h"

int	ft_putnstr_fd(char *s, int fd, int n)
{
	int	count;

	count = 0;
	if ((fd < 0))
		return (-1);
	if (s)
		count += write(fd, s, n);
	else
		count += write(fd, "(null)", n);
	return (count);
}
