/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mqueguin <mqueguin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 14:45:29 by mqueguin          #+#    #+#             */
/*   Updated: 2021/06/08 14:38:56 by mqueguin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

//Tri rapide
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
	sort_b(a, b);
}