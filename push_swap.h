/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hferjani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 12:19:02 by hferjani          #+#    #+#             */
/*   Updated: 2022/10/03 14:58:29 by hferjani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <stddef.h>

/*  a linked list node  */

typedef struct s_list
{
	int				value;
	struct s_list	*next;
}t_list;

/*  Utils    */

void			ft_error(void *free1, void *free2);
void			ft_putstr_fd(char *s, int fd);
int				is_digit(int c);
int				ft_is_number(char *str);
int				ft_no_duplicate(int array_sorted[], int argc);
void			ft_sort_int_tab(int tab[], int size);
int				is_sorted(t_list *stack);
int				is_empty(t_list **stack);
void			push(t_list **head_ref, int new_data);
void			free_stack(t_list **stack);
void			printArray(int array[], int size);

/*  Parsing   */

int				*inputs(int argc, char **argv);
void			ft_index(int array[], int copy[], int argc);
int				ft_atoi(const char *str);
int				ft_lstsize(t_list *lst);

/*  Sort   */

void			radix_sort(t_list **stack_a, t_list **stack_b, int argc);
void			sort_stack(t_list **stack_a, t_list **stack_b, int argc);
void			sort_three(t_list **stack);
void			sort_four(t_list **stack_a, t_list **stack_b);
void			sort_five(t_list **stack_a, t_list **stack_b);

/*  Operations    */

void			rotate(t_list **stack);
void			ra(t_list **stack_a);
void			move_to_front(t_list**headref);
void			rra(t_list **stack_a);
void			ft_swap(int*a, int*b);
void			pairwiseswap(t_list *head);
void			sa(t_list **stack_a);
void			push_stack(t_list **src, t_list **dst);
void			pb(t_list **a, t_list **b);
void			pa(t_list **b, t_list **a);
long long int	ft_latoi(const char *str);

#endif
