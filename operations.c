/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hferjani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 14:57:28 by hferjani          #+#    #+#             */
/*   Updated: 2022/09/23 15:01:19 by hferjani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pb(t_list **a, t_list **b)
{
	push_stack(a, b);
	ft_putstr_fd("pb\n", 1);
}

void	pa(t_list **b, t_list **a)
{
	push_stack(b, a);
	ft_putstr_fd("pa\n", 1);
}

void	ra(t_list **stack_a)
{
	rotate(stack_a);
	ft_putstr_fd("ra\n", 1);
}

void	rra(t_list **stack_a)
{
	move_to_front(stack_a);
	ft_putstr_fd("rra\n", 1);
}

void	sa(t_list **stack_a)
{
	pairwiseswap(*stack_a);
	ft_putstr_fd("sa\n", 1);
}
