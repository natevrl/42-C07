/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbenhado <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/08 20:38:27 by nbenhado          #+#    #+#             */
/*   Updated: 2021/07/10 09:29:09 by nbenhado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>

int	ft_ultimate_range(int	**range, int	min, int	max)
{
	if (min >= max)
	{
		*range = NULL;
		return (0);
	}

	*range  = malloc((max - min) * sizeof(int));
	if (!*range)
		return (-1);
	int	i;

	i = 0;
	while(i < max - min)
	{
		*range[i] = min + i;
		i++;
	}
	return (max - min);
}

#include <stdio.h>

int	main(void)
{
	int *range;

	printf("Warn: Any segfault will mean that arrays are not correctly allocated\n");

	printf("5:%d\n", ft_ultimate_range(&range, 0, 5));
	printf("0, 1, 2, 3, 4 : %d, %d, %d, %d, %d\n", range[0], range[1], range[2], range[3], range[4]);

	printf("0:%d\n", ft_ultimate_range(&range, 3, 3));

	printf("2:%d\n", ft_ultimate_range(&range, -1, 1));
	printf("-1, 0 : %d, %d", range[0], range[1]);
}
