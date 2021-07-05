/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mqueguin <mqueguin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 14:45:29 by mqueguin          #+#    #+#             */
/*   Updated: 2021/07/05 18:22:29 by mqueguin         ###   ########.fr       */
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

void	sort(t_stack *copy)
{
	int		i;
	int		tmp;

	i = 0;
	while (i < copy->len - 1)
	{
		if (copy->num[i] > copy->num[i + 1])
		{
			tmp = copy->num[i];
			copy->num[i] = copy->num[i + 1];
			copy->num[i + 1] = tmp;
			i = 0;
		}
		else
			i++;
	}
}

void	sort_a_b(t_stack *a, t_stack *b)
{
	int		size;
	int		max_num;
	int		max_bits;
	int		i;
	int		j;

	size = a->len;
	max_num = size - 1;
	max_bits = 0;
	while (max_num >> max_bits)
		max_bits++;
	i = 0;
	while (i < max_bits)
	{
		j = -1;
		while (++j < size)
		{
				if (((a->num[0] >> i)&1) == 1)
				{
					printf("ra\n");
					rotate(a);
				}
				else
				{
					printf("pb\n");
					push(b, a);
				}
		}
		while (b->len > 0)
		{
			printf("pa\n");
			push(a, b);
		}
		i++;
		/*printf("Pile A : \n");
	for (int i = 0; i < a->len; i++)
		printf("%d\n", a->num[i]);
	printf("Pile B : \n");
	for (int i = 0; i < b->len; i++)
		printf("%d\n", b->num[i]);*/
	}
}

void	bigsort(t_stack *a, t_stack *b)
{
	int			i;
	int			j;
	int			tmp;
	t_stack 	*copy;

	copy = new_stack(a->len);
	i = -1;
	while (++i < a->len)
		copy->num[i] = a->num[i];
	sort(copy);
	/*printf("Pile A : \n");
	for (int i = 0; i < a->len; i++)
		printf("%d\n", a->num[i]); */
	i = 0;
	while (i < a->len)
	{
		j = -1;
		while (++j < copy->len)
			if (a->num[i] == copy->num[j])
				a->num[i] = j;
		i++;
	}
	i = -1;
	/*while (++i < a->len)
	{
		tmp = ft_atoi(ft_itoa_base(a->num[i], "01"));
		a->num[i] = tmp;
	}*/
	sort_a_b(a, b);
	/*printf("Pile A : \n");
	for (int i = 0; i < a->len; i++)
		printf("%d\n", a->num[i]);
	printf("Pile B : \n");
	for (int i = 0; i < b->len; i++)
		printf("%d\n", b->num[i]);
		*/
}