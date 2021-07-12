/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbenhado <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/08 20:39:00 by nbenhado          #+#    #+#             */
/*   Updated: 2021/07/12 11:31:37 by nbenhado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*• Écrire une fonction qui va concatener l’ensemble des chaîne de caractères pointées
  par strs en les séparants à l’aide de sep.
  • size représente la taille de strs.
  • Si size vaut 0, il faut retourner une chaîne de caractères vide que l’on peut free().
  • Elle devra être prototypée de la façon suivante :*/

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

int	ft_tabstrslen(char	**strs)
{
	int	i;
	int j;
	int stack;

	stack = 0;
	i = 0;
	j = 0;
	while (strs[i][j])
	{
		while(strs[i][j])
			j++;
		stack += j;
		i++;
		j = 0;
	}
	return (stack);
}

/*char	*ft_strcat(char	*dest, char	*src)
  {
  int	max;

  max = ft_strlen(dest);
  while (*src)
  {
  dest[max] = *src;
  max++;
  src++;
  }
  dest[max] = '\0';
  return (dest);
  }
*/
char	*ft_strcpy(char	*dest, char	*src)
{
	int	i;

	i = 0;
	while (src[i] <= '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}


char *ft_strjoin(int size, char **strs, char *sep)
{
	int j;	
	int i = 1;
	int stack = 0;
	char *str_stack;
	while (i != size)
	{
		stack += ft_strlen(strs[i]);
		i++;
	}
	printf("%d\n",  stack); // ne pas oublier de lenlever cette merde
	str_stack  = malloc(stack + 1 * sizeof(char));
	i = 0;
	stack  = 0;
	while (i < size)
	{
		j = 0;
		while (strs[i][j])
		{
			str_stack[stack] = strs[i][j];
			j++;
			stack++;
		}
		while (*sep)
		{
			if (i != size - 1)
				str_stack[stack] = *sep;
				stack++;
				sep++;
		}
		i++;
	}
	return (str_stack);
}

/*int	main()
  {
  char JOUR[7][9]= {"lundi", "mardi", "mercredi",
  "jeudi", "vendredi", "samedi",
  "dimanche"};
  printf("%d\n",  ft_strlen(JOUR));
  printf("%c\n",  JOUR[1][1]);
  }*/



#include <stdio.h>

char *ft_strjoin(int size, char **strs, char *sep);

int	main(int argc, char **argv)
{
	printf("./ex03/output___said___this___is___a___success :\n");
	printf("%s\n",  ft_strjoin(argc, argv, "___"));
}
