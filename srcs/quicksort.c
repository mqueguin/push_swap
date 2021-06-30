/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mqueguin <mqueguin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 14:45:29 by mqueguin          #+#    #+#             */
/*   Updated: 2021/06/30 14:50:26 by mqueguin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

//Tri rapide

static	void	ft_push_last_numbers(t_stack *a, t_stack *b)
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
	/*printf("\nPile A :\n");
	for (int i = 0; i < a->len; i++)
		printf("%d\n", a->num[i]);
	printf("\nPile B : \n");
	for (int i = 0; i < b->len; i++)
		printf("%d\n", b->num[i]);
	*/
}

static int	get_min_number(t_stack *stack)
{
	int		i;
	int		tmpnbr;

	i = 0;
	tmpnbr = stack->num[0];
	while (++i < stack->len)
	{
		if (stack->num[i] < tmpnbr)
			tmpnbr = stack->num[i];
	}
	return (tmpnbr);
}

static int get_biggest_number(t_stack *stack)
{
	int 	i;
	int		tmpnbr;

	i = 0;
	tmpnbr = stack->num[0];
	while (++i < stack->len)
	{
		if (stack->num[i] > tmpnbr)
			tmpnbr = stack->num[i];
	}
	return (tmpnbr);
}

void ft_recursive_sorting(t_stack *a, t_stack *b)
{
	int i;
	int index;

	i = -1;
	b->tmpnbr = get_biggest_number(b);
	if (b->len == 2)
	{
		ft_push_last_numbers(a, b);
		return ;
	}
	while (++i < b->len)
	{
		if (b->tmpnbr == b->num[i])
			break ;
	}
	//printf("Valeur de i : %d\n", i);
	//printf("Valeur de b->len : %d\n", b->len);
	if (i < b->len - i)
	{
	//	printf("Je passe bien ici\n");
		while (i > 0)
		{
			printf("rb\n");
			rotate(b);
			i--;
		}
		printf("pa\n");
		push(a, b);
	}
	else if (i > b->len - i || i == b->len - i)
	{
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
	/*printf("\nPile A :\n");
	for (int i = 0; i < a->len; i++)
		printf("%d\n", a->num[i]);
	printf("\nPile B : \n");
	for (int i = 0; i < b->len; i++)
		printf("%d\n", b->num[i]); */
	if (b->len > 2)
		ft_recursive_sorting(a, b);
	else
		ft_push_last_numbers(a, b) ;
}

void	quicksort(t_stack *a, t_stack *b)
{
	int i;

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
	/*printf("\nPile A :\n");
	for (int i = 0; i < a->len; i++)
		printf("%d\n", a->num[i]);
	printf("\nPile B : \n");
	for (int i = 0; i < b->len; i++)
		printf("%d\n", b->num[i]); */
	ft_recursive_sorting(a, b);
}

void	bigsort(t_stack *a, t_stack *b)
{
	int		i;
	int		pivot;

	pivot = get_pivot(a);
	printf("Valeur du pivot : %d\n", pivot);
	i = -1;
	while (++i < a->len)
	{
		if (a->num[0] <= pivot)
		{
			printf("pb\n");
			push(b, a);
		}
		else
		{
			printf("ra\n");
			rotate(a);
		}
	}
	sort_b(a, b);
	/*printf("\nPile A : \n");
	for (int i = 0; i < a->len; i++)
		printf("%d\n", a->num[i]);
	printf("\nPile B : \n");
	for (int i = 0; i < b->len; i++)
		printf("%d\n", b->num[i]); */
}