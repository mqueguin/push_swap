/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mqueguin <mqueguin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 17:33:40 by mqueguin          #+#    #+#             */
/*   Updated: 2021/08/03 16:52:54 by mqueguin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	get_biggest_number(t_stack *stack)
{
	int		i;
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

