/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   random_element.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramahrez <ramahrez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 13:17:53 by hectordavro       #+#    #+#             */
/*   Updated: 2025/05/06 14:17:55 by ramahrez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

#define MAX_ELEMENT 2000

int	my_rand(int seed)
{
	seed = (1103515245 * seed + 12345) % (1 << 31);
	return (seed);
}

static int	is_duplicate(int *tab, int size, int value)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (tab[i] == value)
			return (1);
		i++;
	}
	return (0);
}


char	**ft_fill_result(int *tab, int size, char **res)
{
	int	i;

	res[0] = ft_strdup("./push_swap");
	if (!res[0])
		return (free(tab), free(res), NULL);
	i = 0;
	while (i < size)
	{
		res[i + 1] = ft_itoa(tab[i]);
		if (!res[i + 1])
			return (NULL); // tu peux gérer le free ici si tu veux plus clean
		i++;
	}
	res[size + 1] = NULL;
	free(tab);
	return (res);
}

char	**ft_random_element(int num_element)
{
	int		seed;
	int		i;
	int		*tab;
	char	**res;

	if (num_element > MAX_ELEMENT)
		num_element = MAX_ELEMENT;
	tab = malloc(sizeof(int) * num_element);
	if (!tab)
		return (NULL);
	seed = 123456789;
	i = 0;
	while (i < num_element)
	{
		seed = my_rand(seed);
		if (!is_duplicate(tab, i, seed % 100000))
			tab[i++] = seed % 100000;
	}
	res = malloc(sizeof(char *) * (num_element + 2));
	if (!res)
		return (free(tab), NULL);
	return (ft_fill_result(tab, num_element, res));
}

