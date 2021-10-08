/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgalio <sgalio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 17:06:25 by sgalio            #+#    #+#             */
/*   Updated: 2021/10/08 17:06:27 by sgalio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_find_max(t_stack *a)
{
	int		max;

	max = a->value;
	while (a)
	{
		if (a->value > max)
			max = a->value;
		else
			a = a->next;
	}
	return (max);
}

void	sort_stack_a(t_stack **a, t_stack **b, int number)
{
	int	i;
	int	key;

	i = 0;
	if (number <= 105)
		key = 15;
	else
		key = 30;
	while ((*a) != NULL)
	{
		if ((*a)->order <= i && i > 0)
		{
			ft_pb(a, b);
			ft_rb(b);
			i++;
		}
		else if ((*a)->order <= i + key)
		{
			ft_pb(a, b);
			i++;
		}
		else if ((*a)->order >= i && ft_lstsize(*a) > 1)
			ft_ra(a);
	}
}

int	define_position(t_stack *b, int max)
{
	int	pos;

	pos = 1;
	while (b->next)
	{
		if (b->value == max)
			break ;
		else
		{
			pos++;
			b = b->next;
		}
	}
	return (pos);
}

void	sort_stack_b(t_stack **a, t_stack **b)
{
	int		max;
	int		pos;
	int		size;

	while ((*b) != NULL)
	{
		size = ft_lstsize(*b);
		max = ft_find_max(*b);
		pos = define_position(*b, max);
		if (pos <= size / 2 && pos != 1)
		{
			while ((*b)->value != max)
				ft_rb(b);
			ft_pa(a, b);
		}
		else if (pos > size / 2)
		{
			while ((*b)->value != max)
				ft_rrb(b);
			ft_pa(a, b);
		}
		else if (pos == 1)
			ft_pa(a, b);
	}
}
