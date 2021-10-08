/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_pa_pb.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgalio <sgalio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 17:06:56 by sgalio            #+#    #+#             */
/*   Updated: 2021/10/08 17:06:58 by sgalio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_pa(t_stack **a, t_stack **b)
{
	t_stack	*tmp;
	t_stack	*tmp_next;

	if ((*b) == NULL)
		check_error_message();
	tmp = *b;
	tmp_next = (*b)->next;
	tmp->next = *a;
	*a = tmp;
	*b = tmp_next;
	write(1, "pa\n", 3);
}

void	ft_pb(t_stack **a, t_stack **b)
{
	t_stack	*tmp;
	t_stack	*tmp_next;

	if ((*a) == NULL)
		check_error_message();
	tmp = *a;
	tmp_next = (*a)->next;
	tmp->next = *b;
	*b = tmp;
	*a = tmp_next;
	write(1, "pb\n", 3);
}
