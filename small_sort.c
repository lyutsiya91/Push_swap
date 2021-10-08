/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgalio <sgalio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 17:03:37 by sgalio            #+#    #+#             */
/*   Updated: 2021/10/08 17:03:39 by sgalio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_three(t_stack **a)
{
	while (!((*a)->value < (*a)->next->value
			&& (*a)->next->value < (*a)->next->next->value))
	{
		if ((*a)->value > (*a)->next->value && (*a)->next->value
			< (*a)->next->next->value && (*a)->value > (*a)->next->next->value)
		{
			ft_ra(a);
			return ;
		}
		if ((*a)->value < (*a)->next->value && (*a)->next->value
			> (*a)->next->next->value && (*a)->value > (*a)->next->next->value)
		{
			ft_rra(a);
			return ;
		}
		else
			ft_sa(a);
	}
}

void	ft_sort_five(t_stack **a, t_stack **b, int number)
{
	t_stack	*tmp;
	int		n;

	tmp = *a;
	n = number;
	while (tmp && n--)
	{
		if (tmp->order == 0 || tmp->order == 4)
			ft_pb(a, b);
		else
			ft_ra(a);
		tmp = *a;
	}
	ft_sort_three(a);
	if (number == 5 && (*b)->value < (*b)->next->value)
		ft_sb(b);
	ft_pa(a, b);
	if (number == 5)
	{
		ft_ra(a);
		ft_pa(a, b);
	}
}

void	small_sort(t_stack **a, t_stack **b, int number)
{
	if (number == 1)
		return ;
	if (number == 2)
	{
		write(1, "sa\n", 3);
		return ;
	}
	if (number == 3)
		ft_sort_three(a);
	if (number > 3)
		ft_sort_five(a, b, number);
}
