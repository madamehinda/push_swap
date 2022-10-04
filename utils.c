/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hferjani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 14:41:30 by hferjani          #+#    #+#             */
/*   Updated: 2022/09/26 13:41:34 by hferjani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_putstr_fd(char *s, int fd)
{
	unsigned int	i;

	i = 0;
	while (s[i] != '\0')
	{
		write(fd, &s[i], 1);
		i++;
	}
}

void	ft_error(void *free1, void *free2)
{
	if (free1 != NULL)
		free(free1);
	if (free2 != NULL)
		free(free2);
	ft_putstr_fd("Error\n", 2);
	exit(EXIT_FAILURE);
}

void	push(t_list**head_ref, int new_data)
{
	t_list	*new_node;
	t_list	*tmp;

	new_node = malloc(sizeof(t_list));
	if (!new_node)
		return ;
	new_node->value = new_data;
	new_node->next = NULL;
	if (!*head_ref)
	(*head_ref) = new_node;
	else
	{
		tmp = (*head_ref);
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new_node;
	}
}

void	ft_sort_int_tab(int tab[], int size)
{
	int	i;

	i = 0;
	while (i < (size - 1))
	{
		if (tab[i] > tab[i + 1])
		{
			ft_swap(&tab[i], &tab[i + 1]);
			i = 0;
		}
		else
			i++;
	}
}

int	ft_no_duplicate(int array_sorted[], int argc)
{
	int	i;

	i = 0;
	while (i + 1 < argc)
	{
		if (array_sorted[i] == array_sorted[i + 1])
			return (1);
		else
			i++;
	}
	return (0);
}
