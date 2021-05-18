/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   number_errors.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mqueguin <mqueguin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 13:10:22 by mqueguin          #+#    #+#             */
/*   Updated: 2021/05/18 13:37:11 by mqueguin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int		has_double(char *str, int *num, int len)
{
	int		nb;
	int		i;

	if (!str)
		return (1);
	nb = ft_atoi(str);
	i = 0;
	while (i < len)
	{
		if (num[i] == nb)
			return (1);
		i++;
	}
	return (0);
}

int		only_number(char *str)
{
	int		nb;
	char	*nb_str;
	int		i;

	i = 0;
	nb = ft_itoa(str);
	nb_str = ft_itoa(nb);
	while ((str[i] == '0' || str[i] == '+') && str[i + 1])
		i++;
	if (str[i] == nb_str[0])
	{
		ft_strdel(&nb_str);
		return (1);
	}
	ft_strdel(&nb_str);
	return (0);
}

int		valid_number(char *str)
{
	if ((ft_atoi(str) > 0 && str[0] == '-')
			 || (ft_atoi(str) < 0 && str[0] != '-'))
		return (0);
	return (1);
}