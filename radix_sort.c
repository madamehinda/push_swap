/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hferjani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 17:54:57 by hferjani          #+#    #+#             */
/*   Updated: 2022/09/23 15:03:28 by hferjani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_list *stack)
{
	while ((stack)->next != NULL)
	{
		if ((stack)->value > (stack)->next->value)
			return (1);
		(stack) = (stack)->next;
	}
	return (0);
}

void	push_stack(t_list **src, t_list **dst)
{
	t_list	*tmp;

	if (*src == NULL)
		return ;
	tmp = (*src);
	(*src) = (*src)->next;
	if (*dst == NULL)
		tmp->next = NULL;
	else
	tmp->next = *dst;
	*dst = tmp;
}

int	is_empty(t_list **stack)
{
	if ((*stack) == NULL)
		return (1);
	return (0);
}

void	radix_sort(t_list **stack_a, t_list **stack_b, int argc)
{
	int	max_len;
	int	i;
	int	j;

	i = 0;
	max_len = 0;
	while ((argc >> max_len) != 0)
		max_len++;
	while (i < max_len)
	{
		j = 0;
		while (j++ < argc)
		{
			if ((((*stack_a)->value >> i) & 1) == 1)
				ra(stack_a);
			else
				pb(stack_a, stack_b);
		}
		while (!is_empty(stack_b))
			pa(stack_b, stack_a);
		i++;
	}
}

void	sort_stack(t_list **stack_a, t_list **stack_b, int argc)
{
	if ((argc == 2) && (is_sorted(*stack_a)) == 1)
		sa(stack_a);
	if ((argc == 3) && (is_sorted(*stack_a)) == 1)
		sort_three(stack_a);
	if ((argc == 4) && (is_sorted(*stack_a)) == 1)
		sort_four(stack_a, stack_b);
	if ((argc == 5) && (is_sorted(*stack_a)) == 1)
		sort_five(stack_a, stack_b);
	if ((argc > 5) && (is_sorted(*stack_a)) == 1)
		radix_sort(stack_a, stack_b, argc);
}
