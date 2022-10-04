/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_5_and_less.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hferjani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 14:54:25 by hferjani          #+#    #+#             */
/*   Updated: 2022/10/03 15:00:54 by hferjani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	highest_index(t_list **head)
{
	int		index;
	t_list	*tmp;

	tmp = (*head);
	index = tmp->value;
	while (tmp)
	{
		if (tmp->value > index)
			index = tmp->value;
		tmp = tmp->next;
	}
	return (index);
}

static int	lowest_index(t_list *head)
{
	int		index;

	index = head->value;
	while (head)
	{
		if (head->value < index)
			index = head->value;
		head = head->next;
	}
	return (index);
}

void	sort_three(t_list **stack)
{
	static int	highest;

	highest = highest_index(stack);
	if ((*stack)->value == highest)
		ra(stack);
	else if ((*stack)->next->value == highest)
		rra(stack);
	if ((*stack)->value > (*stack)->next->value)
		sa(stack);
}

void	sort_four(t_list **stack_a, t_list **stack_b)
{
	static int	lowest;

	lowest = lowest_index(*stack_a);
	while ((*stack_a)->value != lowest)
		ra(stack_a);
	pb(stack_a, stack_b);
	sort_three(stack_a);
	pa(stack_b, stack_a);
}

void	sort_five(t_list **stack_a, t_list **stack_b)
{
	t_list	*tmp;

	tmp = *stack_a;
	while (tmp)
	{
		while (((tmp)->value == 0 || (tmp)->value == 1)
			&& ft_lstsize(*stack_a) > 3)
		{
			pb(stack_a, stack_b);
			tmp = *stack_a;
		}
		if (ft_lstsize(*stack_a) == 3)
			break ;
		ra(stack_a);
		tmp = *stack_a;
	}
	sort_three(stack_a);
	pa(stack_b, stack_a);
	pa(stack_b, stack_a);
	if ((*stack_a)->value > (*stack_a)->next->value)
		sa(stack_a);
}
