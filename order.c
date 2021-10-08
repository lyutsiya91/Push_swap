/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   order.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgalio <sgalio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 17:02:56 by sgalio            #+#    #+#             */
/*   Updated: 2021/10/08 17:02:58 by sgalio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_array(int *order, int number)
{
	int	i;
	int	k;
	int	tmp;

	i = 1;
	while (i < number)
	{
		k = i;
		while (k > 0 && order[k - 1] > order[k])
		{
			tmp = order[k - 1];
			order[k - 1] = order[k];
			order[k] = tmp;
			k--;
		}
		i++;
	}
}

int	check_order(t_stack *a)
{
	while (a->next)
	{
		if (a->value > a->next->value)
			return (0);
		else
			a = a->next;
	}
	return (1);
}

void	define_order(int *order, int number, t_stack **a)
{
	int		n;
	t_stack	*tmp;

	n = 0;
	while (n < number)
	{
		tmp = *a;
		while (tmp)
		{
			if (tmp->value == order[n])
			{
				tmp->order = n;
				break ;
			}
			else
				tmp = tmp->next;
		}
		n++;
	}
}
