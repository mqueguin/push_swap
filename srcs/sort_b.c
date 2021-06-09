/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mqueguin <mqueguin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 13:57:50 by mqueguin          #+#    #+#             */
/*   Updated: 2021/06/08 14:41:59 by mqueguin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sort_b(t_stack *a, t_stack *b)
{
	int	pivot;
	int	i;

	pivot = get_pivot(b);
	i = -1;
	printf("valeur de len b : %d\n", b->len);
	while (++i < b->len)
	{
		if (b->num[0] > pivot)
		{
			printf("pa\n");
			push(b, a);
		}
		else
		{
			printf("rb\n");
			rotate(b);
		}
	}
}