/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mqueguin <mqueguin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 12:12:09 by mqueguin          #+#    #+#             */
/*   Updated: 2021/08/04 18:39:50 by mqueguin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include "../libft/libft.h"

typedef struct s_stack
{
	int			*num;
	int			len;
	int			tmpnbr;
}				t_stack;

t_stack			*new_stack(int len);
void			stack_del(t_stack **stack);
int				valid_number(char *str);
int				only_number(char *str);
int				has_double(char *str, int *num, int len);
void			resolve(t_stack *a, t_stack *b);

/** Instructions **/
void			swap(t_stack *stack);
void			push(t_stack *stack_a, t_stack *stack_b);
void			rotate(t_stack *stack);
void			reverse_rotate(t_stack *stack);

/** Algo **/
int				get_pivot(t_stack *stack_a);
void			radix_sort(t_stack *a, t_stack *b);

int				check_stack_is_valid(t_stack *a, t_stack *b);

void			sort_b(t_stack *a, t_stack *b);

char			*ft_itoa_base(int nbr, char *base);

int				a_is_sorted(t_stack *a);

void			sort_3_numbers(t_stack *a);

void			sort_5_numbers(t_stack *a, t_stack *b, int i, int pivot);

#endif
