/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mqueguin <mqueguin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 12:29:31 by mqueguin          #+#    #+#             */
/*   Updated: 2021/07/06 17:39:05 by mqueguin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	resolve(t_stack *a, t_stack *b)
{
	if (a_is_sorted(a))
		return ;
	if (a->len >= 12)
		radix_sort(a, b);
	else
		quicksort(a, b);
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
