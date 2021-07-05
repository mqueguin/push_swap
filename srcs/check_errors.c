/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mqueguin <mqueguin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 14:41:43 by mqueguin          #+#    #+#             */
/*   Updated: 2021/07/05 18:43:59 by mqueguin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

// Fonction qui permet de verifier si la stack a est trier
int		check_stack_is_valid(t_stack *a, t_stack *b)
{
	int		i;

	i = -1;
	while (++i < a->len)
	{
		if (b->len > 0 || (a->num[i] > a->num[i + 1]))
			return (0);
	}
	return (1);
}

int	a_is_sorted(t_stack *a)
{
	int		i;
	int		j;

	i = 0;
	while (i < a->len)
	{
		j = i + 1;
		while (j < a->len)
		{
			if (a->num[i] > a->num[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}