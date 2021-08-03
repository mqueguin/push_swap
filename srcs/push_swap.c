/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mqueguin <mqueguin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 12:29:31 by mqueguin          #+#    #+#             */
/*   Updated: 2021/08/03 17:38:35 by mqueguin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sort_3_numbers(t_stack*a)
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
}

void	resolve(t_stack *a, t_stack *b)
{
	if (a_is_sorted(a))
		return ;
	if (a->len >= 12 || a->len == 5)
		radix_sort(a, b);
	else if (a->len == 3)
		sort_3_numbers(a);
	//else if (a->len == 5)
	//	sort_5_numbers(a, b);
	else
		quicksort(a, b);
	stack_del(&a);
	stack_del(&b);
}

int	main(int ac, char **av)
{
	t_stack		*stack_a;
	t_stack		*stack_b;
	int			i;

	if (ac > 3)
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
