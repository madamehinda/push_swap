/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hferjani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 14:33:59 by hferjani          #+#    #+#             */
/*   Updated: 2022/09/23 15:04:54 by hferjani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_list **stack)
{
	t_list	*tmp;
	int		first;

	tmp = *stack;
	first = tmp->value;
	if (*stack == NULL)
		return ;
	while (tmp->next != NULL)
	{
		tmp->value = tmp->next->value;
		tmp = tmp->next;
	}
	tmp->value = first;
}

void	move_to_front(t_list **headref)
{
	t_list	*secondlast;
	t_list	*last;

	if (*headref == NULL || (*headref)->next == NULL)
		return ;
	secondlast = NULL;
	last = (*headref);
	while (last->next != NULL)
	{
		secondlast = last;
		last = last->next;
	}
	secondlast->next = NULL;
	last->next = *headref;
	*headref = last;
}

void	ft_swap(int*a, int*b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

void	pairwiseswap(t_list *head)
{
	t_list	*temp;

	temp = head;
	while (temp != NULL && temp->next != NULL)
	{
		ft_swap(&temp->value, &temp->next->value);
		temp = temp->next;
	}
}
