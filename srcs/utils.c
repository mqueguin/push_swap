/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mqueguin <mqueguin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/05 12:17:18 by mqueguin          #+#    #+#             */
/*   Updated: 2021/08/06 19:31:00 by mqueguin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static	void	erase_spaces(char *str)
{
	int		i;

	i = 0;
	while (str[i])
		i++;
	i--;
	while (str[i] == ' ')
		str[i--] = '\0';
}

static	int	return_error(t_stack *a, t_stack *b)
{
	stack_del(&a);
	stack_del(&b);
	return ((ft_putendl_fd("Error", 2)));
}

static	int	count_args(char *str, int *count, char *copy)
{
	char	tmp[500];
	int		j;

	j = 0;
	while (*str++ == ' ')
		;
	str--;
	while (*str != ' ' && *str != '\0')
		tmp[j++] = *str++;
	tmp[j] = '\0';
	if (ft_isdigit(tmp) && tmp[0] != ' ' && tmp[0] != '\0')
		split_arg(str, copy, *count + 1);
	else if (!ft_isdigit(tmp))
	{
		ft_putendl_fd("Error", 2);
		return (0);
	}
	return (1);
}

static	int	fill_args(char *str, char *copy, int count, char *tmp)
{
	int		i;
	int		j;
	t_stack	*a;
	t_stack	*b;

	a = new_stack(count);
	b = new_stack(count);
	b->len = 0;
	i = count;
	while (count > 0)
	{
		j = 0;
		while (*copy++ == ' ')
			;
		copy--;
		while (*copy != ' ' && *copy != '\0')
			tmp[j++] = *copy++;
		tmp[j] = '\0';
		if (!ft_isdigit(tmp) || has_double(tmp, a->num, i - count))
			return (return_error(a, b));
		a->num[i - count] = ft_atoi(tmp);
		count--;
	}
	resolve(a, b);
	return (1);
}

int	split_arg(char *str, char *copy, int count)
{
	char	tmp[500];

	erase_spaces(str);
	if (*str == '\0')
		fill_args(str, copy, count, tmp);
	else
		count_args(str, &count, copy);
	return (1);
}
