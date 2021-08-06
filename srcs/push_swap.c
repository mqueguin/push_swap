/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mqueguin <mqueguin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 12:29:31 by mqueguin          #+#    #+#             */
/*   Updated: 2021/08/06 14:49:36 by mqueguin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static	void	sort_3_numbers_second_part(t_stack *a)
{	
	if (a->num[0] < a->num[2])
	{
		printf("rra\n");
		reverse_rotate(a);
		printf("sa\n");
		swap(a);
	}
	else
	{
		printf("rra\n");
		reverse_rotate(a);
	}
}

void	sort_3_numbers(t_stack *a)
{
	if (a->num[0] > a->num[1] && a->num[1] > a->num[2])
	{
		printf("sa\n");
		swap(a);
		printf("rra\n");
		reverse_rotate(a);
	}
	else if (a->num[0] > a->num[1] && a->num[1] < a->num[2])
	{
		if (a->num[0] > a->num[2])
		{
			printf("ra\n");
			rotate(a);
		}
		else
		{
			printf("sa\n");
			swap(a);
		}
	}
	else if (a->num[0] < a->num[1] && a->num[1] > a->num[2])
		sort_3_numbers_second_part(a);
}

void	resolve(t_stack *a, t_stack *b)
{
	if (a_is_sorted(a))
		return ;
	if (a->len > 3)
		radix_sort(a, b);
	else if (a->len <= 3)
	{
		if (a->len == 2)
		{
			if (a->num[0] > a->num[1])
			{
				printf("sa\n");
				swap(a);
			}
		}
		else
			sort_3_numbers(a);
	}
	/*printf("Pile A :\n");
	for (int i = 0; i < a->len; i++)
		printf("%d\n", a->num[i]);*/
	stack_del(&a);
	stack_del(&b);
}

int	main(int ac, char **av)
{
	t_stack		*stack_a = NULL;
	t_stack		*stack_b = NULL;
	int			i;

	if (ac == 2)
	{
		if (!split_arg(stack_a, stack_b, av[1], av[1], 0))
			return (0);
	}
	else if (ac > 2)
	{
		stack_a = new_stack(ac - 1);
		stack_b = new_stack(ac - 1);
		stack_b->len = 0;
		i = 0;
		while (++i < ac)
		{
			if (!valid_number(av[i]) || !only_number(av[i])
				|| has_double(av[i], stack_a->num, i - 1))
			{
				ft_putendl_fd("Error", 2);
				stack_del(&stack_a);
				stack_del(&stack_b);
				return (0);
			}
			stack_a->num[i - 1] = ft_atoi(av[i]);
		}
		resolve(stack_a, stack_b);
	}
	return (0);
}
