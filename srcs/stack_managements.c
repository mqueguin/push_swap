/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_managements.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mqueguin <mqueguin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 12:43:23 by mqueguin          #+#    #+#             */
/*   Updated: 2021/05/18 13:10:01 by mqueguin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_stack		*new_stack(int len)
{
	t_stack *stack;

	if (!(stack  = (t_stack*)malloc(sizeof(t_stack))))
		exit(0); // On utilise la fonction exit pour quitter le programme
	stack->len = len;
	if (len > 0)
	{
		if (!(stack->num = (int*)malloc(sizeof(int) * len)))
			exit (0);
	}
	else
		stack->num = 0;
	stack->sorted = 0;
	return (stack);
}

// Fonction qui permet de liberer les 2 mallocs (Celui sur num et celui sur la struct)
void		stack_del(t_stack **stack)
{
	if (*stack)
	{
		free((*stack)->num);
		(*stack)->num = 0; 
		free(*stack);
		*stack = 0;
	}
}