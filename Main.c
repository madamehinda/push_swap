/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hferjani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 14:32:29 by hferjani          #+#    #+#             */
/*   Updated: 2022/09/26 15:29:37 by hferjani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char**argv)
{
	int		i;
	int		*array;
	t_list	*a;
	t_list	*b;

	a = NULL;
	b = NULL;
	argc -= 1;
	argv += 1;
	array = inputs(argc, argv);
	i = 0;
	while (i < argc)
		push(&a, array[i++]);
	sort_stack(&a, &b, argc);
	free(array);
	free_stack(&a);
	free_stack(&b);
	return (0);
}
