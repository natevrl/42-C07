/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbenhado <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/08 20:39:00 by nbenhado          #+#    #+#             */
/*   Updated: 2021/07/17 13:49:00 by nbenhado         ###   ########.fr       */
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

char	*ft_strjoin(int	size, char	**strs, char	*sep)
{
	int		j;	
	int		i;
	int		stack;
	char	*str_stack;

	init_var(&i, &stack);
	if (size == 0)
		return ("");
	while (++i != size)
		stack += ft_strlen(strs[i]);
	str_stack = malloc(1000 * sizeof(char));
	init_var2(&i, &stack);
	while (++i < size)
	{
		j = -1;
		while (strs[i][++j])
			str_stack[stack++] = strs[i][j];
		j = -1;
		if (strs[i] != '\0')
			while (sep[++j])
				if (i != size - 1)
					str_stack[stack++] = sep[j];
	}
	return (str_stack);
}
