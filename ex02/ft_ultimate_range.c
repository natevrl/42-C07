/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbenhado <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/08 20:38:27 by nbenhado          #+#    #+#             */
/*   Updated: 2021/07/17 18:48:56 by nbenhado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>

int	ft_ultimate_range(int	**range, int	min, int	max)
{
	int	i;
	int	stack;
	int	*tab;

	stack = max - min;
	if (min >= max)
	{
		return (0);
		*range = NULL;
	}
	tab = malloc(stack * sizeof(int));
	if (!tab)
		return (-1);
	i = 0;
	while (min < max)
	{
		tab[i] = min;
		min++;
		i++;
	}
	*range = tab;
	return (stack);
}
