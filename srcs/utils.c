/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mqueguin <mqueguin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/05 12:17:18 by mqueguin          #+#    #+#             */
/*   Updated: 2021/08/05 18:37:19 by mqueguin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	split_arg(t_stack *a, t_stack *b, char *str, char *copy, int count)
{
	char	tmp[500];
	int		j;
	int		i;

	j = 0;
	if (*str == '\0')
	{
		//printf("COUCOU\n");
		a = new_stack(count);
		b = new_stack(count);
		b->len = 0;
		printf("Valeur de count %d\n", count);
		i = count;
		while (count >= 1)
		{
			//printf("Valeur de copy : %s\n et de *copy : %c\n", copy, *copy);
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
			if (ft_isdigit(tmp))
				a->num[i - count] = ft_atoi(tmp);
			else
			{
				ft_putendl_fd("Error", 2);
				stack_del(&a);
				stack_del(&b);
				return (0);
			}
			//printf("Valeur de a->num[0] : %d %d %d\n", a->num[0], a->num[1], a->num[2]);
			count--;
		}
		//printf("Valeur de a->len : %d\n et a->num[2] : %d\n", a->len, a->num[2]);
		printf("Valeur de a->len : %d\n", a->len);
		printf("Pile A :\n");
		for (int i = 0;i < a->len; i++)
			printf("%d\n", a->num[i]);
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
		split_arg(a, b, str, copy, count + 1);
		//else
			//return (0);
	}
	return (1);
}
