/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mqueguin <mqueguin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 14:45:29 by mqueguin          #+#    #+#             */
/*   Updated: 2021/07/06 17:37:12 by mqueguin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	ft_push_last_numbers(t_stack *a, t_stack *b)
{
	if (b->num[0] > b->num[1])
	{
		printf("pa\n");
		push(a, b);
		printf("pa\n");
		push(a, b);
	}
	else
	{
		printf("sb\n");
		swap(b);
		printf("pa\n");
		push(a, b);
		printf("pa\n");
		push(a, b);
	}
}

void	reverse_rotate_sorting(t_stack *a, t_stack *b, int i)
{
	int		index;

	index = b->len - i;
	while (index > 0)
	{
		printf("rrb\n");
		reverse_rotate(b);
		index--;
	}
	printf("pa\n");
	push(a, b);
}

void	rotate_sorting(t_stack *a, t_stack *b, int i)
{
	while (i > 0)
	{
		printf("rb\n");
		rotate(b);
		i--;
	}
	printf("pa\n");
	push(a, b);
}

void	ft_recursive_sorting(t_stack *a, t_stack *b)
{
	int		i;

	i = -1;
	b->tmpnbr = get_biggest_number(b);
	if (b->len == 2)
	{
		ft_push_last_numbers(a, b);
		return ;
	}
	while (++i < b->len)
		if (b->tmpnbr == b->num[i])
			break ;
	if (i < b->len - i)
		rotate_sorting(a, b, i);
	else if (i > b->len - i || i == b->len - i)
		reverse_rotate_sorting(a, b, i);
	if (b->len > 2)
		ft_recursive_sorting(a, b);
	else
		ft_push_last_numbers(a, b);
}

void	quicksort(t_stack *a, t_stack *b)
{
	int		i;

	i = -1;
	a->tmpnbr = get_biggest_number(a);
	while (a->len > 1)
	{
		if (a->num[0] == a->tmpnbr)
		{
			rotate(a);
			printf("ra\n");
		}
		else if (a->len > 1)
		{
			push(b, a);
			printf("pb\n");
		}
	}
	ft_recursive_sorting(a, b);
}
