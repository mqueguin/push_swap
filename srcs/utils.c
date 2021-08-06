/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mqueguin <mqueguin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/05 12:17:18 by mqueguin          #+#    #+#             */
/*   Updated: 2021/08/06 14:21:26 by mqueguin         ###   ########.fr       */
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
	//printf("Valeur de str : %s\n", str);
}

int	split_arg(t_stack *a, t_stack *b, char *str, char *copy, int count)
{
	char	tmp[500];
	int		j;
	int		i;

	j = 0;
	erase_spaces(str);
	if (*str == '\0')
	{
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
			//printf("Valeur de *copy : %c------------\n", *copy);
			while (*copy != ' ' && *copy != '\0')
				tmp[j++] = *copy++;
			//printf("Valeur de tmp : %s\n", tmp);
			tmp[j] = '\0';
			//printf("Valeur de tmp apres '0' : %s\n", tmp);
			if (!ft_isdigit(tmp) || has_double(tmp, a->num, i - count))
			{
				ft_putendl_fd("Error", 2);
				stack_del(&a);
				stack_del(&b);
				return (0);
			}
			else
				a->num[i - count] = ft_atoi(tmp);
			//printf("Valeur de a->num[0] : %d %d %d\n", a->num[0], a->num[1], a->num[2]);
			count--;
		}
		//printf("Valeur de a->len : %d\n et a->num[2] : %d\n", a->len, a->num[2]);
		//printf("Valeur de a->len : %d\n", a->len);
		//printf("Pile A :\n");
		/*for (int i = 0;i < a->len; i++)
			printf("%d\n", a->num[i]); */
		resolve(a, b);
			return (1);
	}
	else
	{
		while (*str++ == ' ')
			;
		str--;
		//printf("Valeur de str : %c\n", *str);
		while (*str != ' ' && *str != '\0')
			tmp[j++] = *str++;
		tmp[j] = '\0';
		//printf("Valeur de tmp : %s\n", tmp);
		//if (ft_isdigit(tmp))
		if (ft_isdigit(tmp) && tmp[0] != ' ' && tmp[0] != '\0')
			split_arg(a, b, str, copy, count + 1);
		else if (!ft_isdigit(tmp))
		{
			ft_putendl_fd("Error", 2);
			return (0);
		}
	}
	return (1);
}
