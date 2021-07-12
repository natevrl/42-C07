/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbenhado <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/12 15:40:43 by nbenhado          #+#    #+#             */
/*   Updated: 2021/07/12 16:08:24 by nbenhado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

	i = 0;
	max = ft_strlen(to_find);
	if (*to_find == '\0')
		return (str);
	while (str[i] != '\0')
	{
		if (str[i] == to_find[0])
		{
			j = 0;
			while (str[i] == to_find[j])
			{
				if (j == max - 1)
					return (str + (i - j));
				i++;
				j++;
			}
		}
		else
			i++;
	}
	return (0);
}

char **ft_split(char *str, char *charset)
{

}
