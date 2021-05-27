/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mqueguin <mqueguin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/22 12:04:21 by mqueguin          #+#    #+#             */
/*   Updated: 2021/05/26 14:58:47 by mqueguin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

//Inverse de la fct rotate
void	reverse_rotate(t_stack *stack)
{
	int		tmp;
	int		i;

	tmp = stack->num[stack->len - 1];
	i = stack->len - 1;
	while (i >= 1)
	{
		stack->num[i] = stack->num[i - 1];
		i--;
	}
	stack->num[0] = tmp;
}

//Décale tous les élements de 1 vers le sommet (le premier élément devient le dernier)
void	rotate(t_stack *stack)
{
	int		tmp;
	int		i;

	tmp = stack->num[0]; // Le premier élément qui deviendra le dernier
	i = 0;
	while (i + 1 < stack->len)
	{
		stack->num[i] = stack->num[i + 1];
		i++;
	}
	stack->num[i] = tmp;
}

//Pousse b vers a
void	push(t_stack *stack_a, t_stack *stack_b)
{
	int		i;

	i = stack_a->len - 1;
	while (i >= 0)
	{
		stack_a->num[i + 1] = stack_a->num[i];
		i--;
	}
	stack_a->num[0] = stack_b->num[0];
	i = 0;
	while (i < stack_b->len)
	{
		stack_b->num[i] = stack_b->num[i + 1];
		i++;
	}
	stack_a->len++;
	stack_b->len--;
}

//Swap les 2 premiers nombre de la pile
void	swap(t_stack *stack)
{
	int		tmp;

	tmp = stack->num[0];
	stack->num[0] = stack->num[1];
	stack->num[1] = tmp;
}