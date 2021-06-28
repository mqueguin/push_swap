/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mqueguin <mqueguin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 13:57:50 by mqueguin          #+#    #+#             */
/*   Updated: 2021/06/28 16:50:28 by mqueguin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static	void	push_last_2_numbers(t_stack *a, t_stack *b)
{
	//Si num[0] > num[1]
	if (b->num[0] > b->num[1])
	{
		printf("pa\n");
		push(a, b);
		printf("pa\n");
		push(a, b);
	}
	//si num[0] < num[1]
	if (b->num[0] < b->num[1])
	{
		printf("rb\n");
		rotate(b);
		printf("pa\n");
		push(a, b);
		printf("pa\n");
		push(a, b);
	}
	printf("\nPile A : \n");
	for (int i = 0; i < a->len; i++)
		printf("%d\n", a->num[i]);
	printf("\nPile B : \n");
	for (int i = 0; i < b->len; i++)
		printf("%d\n", b->num[i]);
}

void	sort_b(t_stack *a, t_stack *b)
{
	int	pivot;
	int	i;

	if (b->len <= 2)
		return (push_last_2_numbers(a, b));
	pivot = get_pivot(b);
	i = -1;
	printf("valeur de len b : %d\n", b->len);
	printf("Valeur du pivot : %d\n", pivot);
	while (++i < b->len)
	{
		if (b->num[0] > pivot)
		{
			printf("pa\n");
			push(a, b);
		}
		else
		{
			printf("rb\n");
			rotate(b);
		}
	}
	printf("\nPile A : \n");
	for (int i = 0; i < a->len; i++)
		printf("%d\n", a->num[i]);
	printf("\nPile B : \n");
	for (int i = 0; i < b->len; i++)
		printf("%d\n", b->num[i]);
	sort_b(a, b);
}