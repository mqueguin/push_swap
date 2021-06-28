/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mqueguin <mqueguin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 14:45:29 by mqueguin          #+#    #+#             */
/*   Updated: 2021/06/28 19:06:39 by mqueguin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

//Tri rapide
/*
void	quicksort(t_stack *a, t_stack *b)
{
	int		pivot;
	int		len;
	int		first;
	int		i;

	pivot = get_pivot(a);
	len = a->len;
	i = -1;
	printf("Valeur du pivot : %d\n", pivot);
	while (++i < len)
	{
		if (a->num[0] <= pivot)
		{
			printf("pb\n");
			push(b, a); //On pousse a vers b 
		}
		else
		{
			printf("ra\n");
			rotate(a);
		}
	}
	printf("\nPile A : \n");
	for (int i = 0; i < a->len; i++)
		printf("%d\n", a->num[i]);
	printf("\nPile B : \n");
	for (int i = 0; i < b->len; i++)
		printf("%d\n", b->num[i]);
	sort_b(a, b); /
}
*/
static void get_biggest_number(t_stack *a, t_stack *b)
{
	int i;

	i = 0;
	a->tmpnbr = 0;
	if (!(a) && !(b))
		return ;
	if (b->len == 0)
	{
		a->tmpnbr = a->num[0];
		while (i++ < a->len)
		{	
			if (a->num[i] > a->tmpnbr)
				a->tmpnbr = a->num[i];				
		}
	}
	else 
	{
		b->tmpnbr = b->num[0];
		while (i++ < b->len)
		{
			if (b->num[i] > b->tmpnbr)
			b->tmpnbr = b->num[i];
		}
	} 
}

void ft_recursive_sorting(t_stack *a, t_stack *b)
{
	int i;
	int index;
	int index2;

	i = -1;
	get_biggest_number(a, b);
	while (++i < b->len)
	{
		if (b->tmpnbr == b->num[i])
		{
			if (i >= b->len/2)
			{
				index = i;
				while (index < b->len) 
				{	
					index++;
					if (index == b->len)
					{
						reverse_rotate(b);
						push(a,b);
					}
					else
						reverse_rotate(b);
				}
			}
			else
			{
				index2 = i;
				while (index2 < b->len)
				{
					index2++;
					if (index2 == b->len)
					{	
						rotate(b);
						push(a,b);
					}
					else
						rotate(b);
				}
			}
		}
	}
	printf("\nPile A :\n");
	for (int i = 0; i < a->len; i++)
		printf("%d\n", a->num[i]);
	printf("\nPile B : \n");
	for (int i = 0; i < b->len; i++)
		printf("%d\n", b->num[i]);
	if (b->len > 2)
		ft_recursive_sorting(a, b);
	else
		return ;
}

void	quicksort(t_stack *a, t_stack *b)
{
	int i;

	i = -1;
	get_biggest_number(a, b);
	printf("tmpnbr = %d\n", a->tmpnbr);
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
	printf("\nPile A :\n");
	for (int i = 0; i < a->len; i++)
		printf("%d\n", a->num[i]);
	printf("\nPile B : \n");
	for (int i = 0; i < b->len; i++)
		printf("%d\n", b->num[i]);
	ft_recursive_sorting(a, b);
}