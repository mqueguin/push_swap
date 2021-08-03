/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_5_numbers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mqueguin <mqueguin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/03 16:54:48 by mqueguin          #+#    #+#             */
/*   Updated: 2021/08/03 17:37:52 by mqueguin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sort_5_numbers(t_stack *a, t_stack *b)
{
	int	i;
	int	pivot;

	pivot = get_pivot(a); //Normalement le pivot est 2
	i = -1;
	//printf("Pile A :\n");
	//for (int i = 0; i < a->len; i++)
	//	printf("%d\n", a->num[i]);
	while (a->len > 3)
	{
		i++;
		if (a->num[0] < pivot)
		{
			printf("pb\n");
			push(b, a);
		}
		else if (a->num[i] < pivot)
		{
			if (i <= a->len - i)
			{
				while (i-- > 0)
				{
					printf("ra\n");
					rotate(a);
				}
			}
			else
			{
				while (a->len - i-- > 0)
				{
					printf("rra\n");
					reverse_rotate(a);
				}
			}
		}
	}
	sort_3_numbers(a);
	if (b->num[0] < b->num[1])
	{
		printf("sb\n");
		swap(b);
	}
	while (b->len > 0)
	{
		printf("pa\n");
		push(a, b);
	}
}
