/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_sa_sb.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgalio <sgalio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 17:07:09 by sgalio            #+#    #+#             */
/*   Updated: 2021/10/08 17:07:10 by sgalio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sa(t_stack **a)
{
	t_stack	*tmp;
	t_stack	*first;
	t_stack	*second;

	if ((*a) == NULL || (*a)->next == NULL)
		check_error_message();
	first = *a;
	second = (*a)->next;
	tmp = second->next;
	second->next = first;
	first->next = tmp;
	*a = second;
	write(1, "sa\n", 3);
}

void	ft_sb(t_stack **b)
{
	t_stack	*tmp;
	t_stack	*first;
	t_stack	*second;

	if ((*b) != NULL || (*b)->next != NULL)
		check_error_message();
	first = *b;
	second = (*b)->next;
	tmp = second->next;
	second->next = first;
	first->next = tmp;
	*b = second;
	write(1, "sb\n", 3);
}
