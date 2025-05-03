/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   random_element.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramahrez <ramahrez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 13:17:53 by hectordavro       #+#    #+#             */
/*   Updated: 2025/05/03 18:18:06 by ramahrez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

#define MAX_ELEMENT 2000

int	my_rand(int seed)
{
	seed = (1103515245 * seed + 12345) % (1 << 31);
	return (seed);
}

char	**ft_random_element(int num_element)
{
	int seed = 123456789;
	int i = 0;
	char **res;
	int *temp;

	if (num_element > MAX_ELEMENT)
		num_element = MAX_ELEMENT;

	temp = malloc(sizeof(int) * num_element);
	if (!temp)
		return NULL;

	while (i < num_element)
	{
		seed = my_rand(seed);
		temp[i++] = seed % 100000;
	}

	res = malloc(sizeof(char *) * (num_element + 1));
	if (!res)
		return free(temp), NULL;

	res[num_element] = NULL;
	i = 0;
	while (i < num_element)
	{
		res[i] = ft_itoa(temp[i]);
		i++;
	}
	free(temp);
	return res;
}
