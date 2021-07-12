/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbenhado <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/08 20:39:00 by nbenhado          #+#    #+#             */
/*   Updated: 2021/07/12 12:59:58 by nbenhado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Se renseigner si il faut afficher le ./a.out ou non
// reussir a free si size = 0
// chercher dautres cas speciales
// ily a une erreur lorsque le 2 eme argument et une seule lettre


#include <stdlib.h>
#include <stdio.h>

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

char	*ft_strjoin(int	size, char	**strs, char	*sep)
{
	int		j, i, stack;	
char	*str_stack;

	i = 1;
	stack = 0;

	if (size == 0)
		return "";

	while (i != size)
	{
		stack += ft_strlen(strs[i]);
		i++;
	}
	str_stack = malloc(stack + 1 * sizeof(char));
	i = 0;
	stack = 0;
	while (i < size)
	{
		j = 0;
		while (strs[i][j])
		{
			str_stack[stack] = strs[i][j];
			j++;
			stack++;
		}
		j = 0;
		while (sep[j])
		{
			if (i != size - 1)
				str_stack[stack] = sep[j];
			stack++;
			j++;
		}
		i++;
	}
	return (str_stack);
}


char *ft_strjoin(int size, char **strs, char *sep);

int	main(int argc, char **argv)
{
	printf("./ex03/output___said___this___is___a___success :\n");
	printf("%s\n",  ft_strjoin(argc, argv, "___"));
}
