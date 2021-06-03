/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mqueguin <mqueguin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 14:45:29 by mqueguin          #+#    #+#             */
/*   Updated: 2021/06/03 15:36:58 by mqueguin         ###   ########.fr       */
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
	while (++i < len)
	{
		if (a->num[i] < pivot)
		{
			printf("pb");
			push(b, a); //On pousse a vers b 
		}
		else
		{
			printf("ra");
			rotate(a);
		}
	}
	
}