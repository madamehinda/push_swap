/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_and_errors.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hferjani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 11:34:30 by hferjani          #+#    #+#             */
/*   Updated: 2022/10/03 14:50:36 by hferjani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_digit(int c)
{
	if ((c >= 48) && (c <= 57))
		return (1);
	else
		return (0);
}

int	ft_is_number(char *str)
{
	int	i;

	i = 0;
	if ((str[i] == '-' || str[i] == '+') && str[i + 1] != '\0')
		i++;
	while (str[i] && is_digit(str[i]))
		i++;
	if (str[i] != '\0' && !is_digit(str[i]))
		return (0);
	return (1);
}

int	ft_atoi(const char *str)
{
	int		i;
	int		signe;
	int		resultat;

	i = 0;
	signe = 1;
	resultat = 0;
	while ((str[i] == ' ') || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			signe *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		resultat = resultat * 10 + (str[i] - 48);
		i++;
	}
	resultat *= signe;
	return (resultat);
}

int	*inputs(int argc, char **argv)
{
	int	i;
	int	*array;
	int	*copy;

	array = NULL;
	copy = NULL;
	i = -1;
	if (!argv)
		return (NULL);
	array = malloc (argc * sizeof (*array));
	copy = malloc (argc * sizeof (*copy));
	if (!copy || !array)
		return (NULL);
	while (++i < argc)
	{
		array[i] = ft_atoi(argv[i]);
		if (!ft_is_number(argv[i]) || array[i] != ft_latoi(argv[i]))
			ft_error(array, copy);
		copy[i] = array[i];
	}
	ft_index(array, copy, argc);
	free(copy);
	return (array);
}

void	ft_index(int array[], int copy[], int argc)
{
	int	i;
	int	j;
	int	tmp;

	i = 0;
	ft_sort_int_tab(copy, argc);
	if (ft_no_duplicate(copy, argc) == 1)
		ft_error(array, copy);
	while (i < argc)
	{
		j = 0;
		tmp = 0;
		while (j < argc)
		{
			if (array[i] > copy[j])
				tmp = tmp + 1;
			j++;
		}
		array[i] = tmp;
		i++;
	}
}
