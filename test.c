/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mqueguin <mqueguin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 19:29:31 by mqueguin          #+#    #+#             */
/*   Updated: 2021/05/27 14:25:37 by mqueguin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int		main()
{
	int	tab[6] = {0, 1, 2, 3, 4, 5};

	int tmp;

	tmp = tab[5];
	int j = 5;
	while (j >= 1)
	{
		tab[j] = tab[j - 1];
		j--;
	}
	tab[0] = tmp;
	printf("----------\n");
	printf("tab[0] : %d\n", tab[0]);
	printf("tab[1] : %d\n", tab[1]);
	printf("tab[2] : %d\n", tab[2]);
	printf("tab[3] : %d\n", tab[3]);
	printf("tab[4] : %d\n", tab[4]);
	printf("tab[5] : %d\n", tab[5]);
	return (0);

}