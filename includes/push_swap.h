/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mqueguin <mqueguin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 12:12:09 by mqueguin          #+#    #+#             */
/*   Updated: 2021/06/03 14:57:27 by mqueguin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include <unistd.h>
#include <stdio.h>

typedef struct	s_stack
{
	int			*num;
	int			len;
	int			sorted;
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


int				check_stack_is_valid(t_stack *a, t_stack *b);
#endif