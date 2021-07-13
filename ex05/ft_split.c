/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbenhado <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/12 15:40:43 by nbenhado          #+#    #+#             */
/*   Updated: 2021/07/14 00:09:24 by nbenhado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>


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

char	*ft_strstr(char	*str, char	*to_find)
{
	int	i;
	int	max;
	int	j;
	char **tab;
	int n;
	n = 0;
	tab = malloc(ft_strlen(str)+100 * sizeof(char));
	i = 0;
	max = ft_strlen(to_find);
	if (*to_find == '\0')
		return (str);
	while (str[i])
	{
		if (str[i] == to_find[0])
		{
			j = 0;
			while (str[i] == to_find[j])
			{
				if (j == max - 1)
				{
						tab[n] = str;
						printf("%s\n", tab[n]);
						n++;
				}
				i++;
				j++;
			}
		}
		else
			i++;
	}
	return *tab;
}

int is_in_charset(char c, char *charset)
{
	int i;

	i = 0;
	while (charset[i])
	{
		if (c == charset[i])
			return (1);
		i++;
	}
	return (0);
}
/*
char **ft_split(char *str, char *charset)
{
	int	i;
	int	j;
	int memory;
	char *tab;

	tab = malloc(100 * sizeof(char));
	while (str[i])
	{
		if (is_in_charset(str[i], charset))
			while (is_in_charset(str[i++], charset))

			write(1, "y", 1);
				
					//tab[] = str[i]
					//memory += (i + j); // index du debut de la prochaine STR 
					// le premier i quna il rentre + le dernier j (index du charset)
					// malloc la str du dernier charset a lactuel
		i++;
	}


}*/

char *ft_split_copy(char *str, int fin, int debut)
{
	int taille;
	int	i = 0;
	taille = fin - debut;
	char *tab;

	tab = malloc(taille * sizeof(char));
	if (!tab)
		return (NULL);
	while (debut < fin)
	{
		tab[i] = str[debut];
		debut++;
		i++;
	}
	tab[i] = '\0';
	return (tab);
}

char  **test(char *str, char *charset)
{
	int i = 0;
	int j;
	int f = 0;
	int before_charset;
	int charset_end = 0;
	char **tab_de_tab;

	tab_de_tab = malloc(100 * sizeof(char *));
	if (!tab_de_tab)
		return (NULL);
	while (str[i])
	{
		if (is_in_charset(str[i], charset))
		{
			j = 0;
			while (is_in_charset(str[i], charset))
			{
				i++;
				j++;
			}
			before_charset = i - j; // str avant de renconter un charset (fin a copier)
			tab_de_tab[f] = ft_split_copy(str, before_charset, charset_end);
			f++;
			charset_end += i; // fin du charset (debut de la nouvelle str a copier)
			i--;
		}
		i++;
	}
	return (tab_de_tab);
}

int main()
{
	char **tab;

	tab = test("hdsdsdsdd11111111sds1s1s1s11111111sss1", "1");

	printf("%s\n", tab[0]);
	printf("%s\n", tab[1]);
	printf("%s\n", tab[2]);
	printf("%s\n", tab[3]);
	printf("%s\n", tab[4]);
	printf("%s\n", tab[5]);
	printf("%s\n", tab[6]);
}
/*
#include <string.h>
#include <stdio.h>

char	*ft_strstr(char *str, char *to_find);


int	main(void)
{
	char s1a[] = "1,,,2,,,3,,,4,5,6";
	char s2a[] = ",,,";

	printf("%s\n", ft_strstr(s1a, s2a));
	int		main(void)
{
	char **tab;

//	tab = ft_split("Ceci&est$un##############################################################################################################################################################succes@!", "&$#@");
}
}*/
