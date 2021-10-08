/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_ra_rra_rb_rrb.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgalio <sgalio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 17:07:03 by sgalio            #+#    #+#             */
/*   Updated: 2021/10/08 17:07:04 by sgalio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_ra(t_stack **a)
{
	t_stack	*tmp;
	t_stack	*tmp_next;
	t_stack	*pointer;

	if ((*a) == NULL || (*a)->next == NULL)
		check_error_message();
	tmp = *a;
	tmp_next = (*a)->next;
	pointer = *a;
	while (pointer->next)
		pointer = pointer->next;
	tmp->next = NULL;
	pointer->next = tmp;
	*a = tmp_next;
	write(1, "ra\n", 3);
}

void	ft_rb(t_stack **b)
{
	t_stack	*tmp;
	t_stack	*tmp_next;
	t_stack	*pointer;

	if ((*b) == NULL || (*b)->next == NULL)
		check_error_message();
	tmp = *b;
	tmp_next = (*b)->next;
	pointer = *b;
	while (pointer->next)
		pointer = pointer->next;
	tmp->next = NULL;
	pointer->next = tmp;
	*b = tmp_next;
	write(1, "rb\n", 3);
}

void	ft_rra(t_stack **a)
{
	t_stack	*pointer;
	t_stack	*pointer_previous;

	if ((*a) == NULL || (*a)->next == NULL)
		check_error_message();
	pointer = *a;
	pointer_previous = *a;
	while (pointer->next)
		pointer = pointer->next;
	while (pointer_previous->next != pointer)
		pointer_previous = pointer_previous->next;
	pointer->next = *a;
	pointer_previous->next = NULL;
	*a = pointer;
	write(1, "rra\n", 4);
}

void	ft_rrb(t_stack **b)
{
	t_stack	*pointer;
	t_stack	*pointer_previous;

	if ((*b) == NULL || (*b)->next == NULL)
		check_error_message();
	pointer = *b;
	pointer_previous = *b;
	while (pointer->next)
		pointer = pointer->next;
	while (pointer_previous->next != pointer)
		pointer_previous = pointer_previous->next;
	pointer->next = *b;
	pointer_previous->next = NULL;
	*b = pointer;
	write(1, "rrb\n", 4);
}

void	ft_rrr(t_stack **a, t_stack **b)
{
	if ((*a) == NULL || (*a)->next == NULL)
		check_error_message();
	if ((*b) == NULL || (*b)->next == NULL)
		check_error_message();
	ft_rra(a);
	ft_rrb(b);
}
