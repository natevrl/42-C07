/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbenhado <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/08 20:39:00 by nbenhado          #+#    #+#             */
/*   Updated: 2021/07/17 19:17:26 by nbenhado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char	*str)
{
	int	index;

	index = 0;
	while (str[index] != '\0')
	{
		index++;
	}
	return (index);
}

void	init_var(int	*i, int	*stack)
{
	*i = 0;
	*stack = 0;
}

void	init_var2(int	*i, int	*stack)
{
	*i = -1;
	*stack = 0;
}

// tab[0] = i, tab[1] = j, tab[2] = stack
char	*ft_strjoin(int	size, char	**strs, char	*sep)
{
	int		tab[3];
	char	*str_stack;

	init_var(&tab[0], &tab[2]);
	if (size == 0)
		return ("");
	while (++tab[0] != size)
		tab[2] += ft_strlen(strs[tab[0]]);
	str_stack = (char *)malloc(sizeof(char) * tab[2] + 1);
	if (str_stack == NULL)
		return (NULL);
	init_var2(&tab[0], &tab[2]);
	while (++tab[0] < size)
	{
		tab[1] = -1;
		while (strs[tab[0]][++tab[1]])
			str_stack[tab[2]++] = strs[tab[0]][tab[1]];
		tab[1] = -1;
		if (strs[tab[0]] != '\0')
			while (sep[++tab[1]])
				if (tab[0] != size - 1)
					str_stack[tab[2]++] = sep[tab[1]];
	}
	return (str_stack);
}
