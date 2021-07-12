/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbenhado <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/08 20:37:51 by nbenhado          #+#    #+#             */
/*   Updated: 2021/07/09 15:20:10 by nbenhado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int *ft_range(int min, int max)
{
	if (min >= max)
		return (NULL);
	int *tab_int;

	tab_int = malloc((max - min) * sizeof(int));
	if (!tab_int)
		return (NULL);	
	int i = 0;
	while(i < max - min)
	{
		tab_int[i] = min + i;
		i++;
	}


	return (tab_int);
}


int	main(void)
{
	int *range;

	printf("Warn: Don't forget to check that the array is of the correct size manually ! Can't know size of `malloc` arrays\n");
	printf("Warn: Any segfault will mean that arrays are not correctly allocated\n");

	range = ft_range(0, 5);
	printf("0, 1, 2, 3, 4 : %d, %d, %d, %d, %d\n", range[0], range[1], range[2], range[3], range[4]);

	range = ft_range(3, 3);

	range = ft_range(-1, 1);
	printf("-1, 0 : %d, %d, %d", range[0], range[1], range[200]);
}
