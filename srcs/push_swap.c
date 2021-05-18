/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mqueguin <mqueguin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 12:29:31 by mqueguin          #+#    #+#             */
/*   Updated: 2021/05/18 13:43:18 by mqueguin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	resolve(t_stack *a, t_stack *b)
{
	if (a->len >= 12)
		quicksort(a, b);
	else
		short_sort(a, b);
	stack_del(&a);
	stack_del(&b);
}

int		main(int ac, char **av)
{
	t_stack		*stack_a;
	t_stack		*stack_b;
	int			i;

	if (ac > 3)
	{
		stack_a = new_stack(ac - 1); // fonction qui va permettre de creer une stack avec le nombre d int
		stack_b = new_stack(ac - 1); // Pareil qu au dessus sauf que l'on met tout a 0 vu qu'au debut de la struct c'est vide
		stack_b->len = 0; // On met la taille de la stack b a 0 car vide au debut
		i = 0;
		while (++i < ac)
		{
			//Ici checker en premier si le nombre est valide
			//Si le nombre est pas valide free la struct et afficher error avec ft_putendl_fd et renvoyer 0
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
		// Ici on appelle la fonction qui va commencer la resolution
		resolve(stack_a, stack_b);
	}
	return (0);
}