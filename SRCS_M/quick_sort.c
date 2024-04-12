/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baouragh <baouragh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 20:18:02 by baouragh          #+#    #+#             */
/*   Updated: 2024/04/12 15:00:08 by baouragh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

void	swap(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

static int	partition(int *array, int start, int end)
{
	int	pivot;
	int	i;
	int	j;

	j = start;
	pivot = array[end];
	i = start - 1;
	while (j <= end - 1)
	{
		if (array[j] <= pivot)
		{
			i++;
			swap(&array[j], &array[i]);
		}
		j++;
	}
	i++;
	swap(&array[j], &array[i]);
	return (i);
}

void	quick_sort(int *array, int start, int end)
{
	int	pivot;

	if (start >= end)
		return ;
	pivot = partition(array, start, end);
	quick_sort(array, start, pivot - 1);
	quick_sort(array, pivot + 1, end);
}
/*
	int main()
	{
		int array[] = {4,7,2,1,6,5,23,21,0,-1,3,0};
		int i;
		i = 0;
		quick_sort(array, 0, (sizeof(array) / sizeof(array[0])) - 1);

		while (i < (sizeof(array) / sizeof(array[0])))
		{
			printf("%d",array[i]);
			i++;
		}
	}

*/
