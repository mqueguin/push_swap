/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_pivot.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mqueguin <mqueguin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 14:34:26 by mqueguin          #+#    #+#             */
/*   Updated: 2021/08/04 17:16:19 by mqueguin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	lowest_number(t_stack *a, t_stack *b)
{
	int	i;
	int	first;

	first = a->num[0];
	i = 0;
	while (++i < a->len)
	{
		if (first > a->num[i])
			first = a->num[i];
	}
	i = -1;
	while (++i < b->len)
	{
		if (first > b->num[i])
			first = b->num[i];
	}
	return (first);
}

int	get_pivot(t_stack *stack_a)
{
	int	i;
	int	j;
	int	pivot;
	int	left;
	int	right;

	i = 0;
	left = 0;
	right = 1;
	while (left != right)
	{
		right = !(stack_a->len % 2);
		left = 0;
		pivot = stack_a->num[i];
		j = -1;
		while (++j < stack_a->len)
		{
			if (pivot < stack_a->num[j])
				right++;
			else if (pivot > stack_a->num[j])
				left++;
		}
		i++;
	}
	return (pivot);
}
