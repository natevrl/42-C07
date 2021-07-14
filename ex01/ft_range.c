/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbenhado <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/08 20:37:51 by nbenhado          #+#    #+#             */
/*   Updated: 2021/07/14 17:41:57 by nbenhado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int	min, int	max)
{
	int	*tab_int;
	int	i;

	if (min >= max)
		return (NULL);
	tab_int = malloc((max - min) * sizeof(int));
	if (!tab_int)
		return (NULL);
	i = 0;
	while (i < max - min)
	{
		tab_int[i] = min + i;
		i++;
	}
	return (tab_int);
}
