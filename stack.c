/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgalio <sgalio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 17:00:30 by sgalio            #+#    #+#             */
/*   Updated: 2021/10/08 17:00:33 by sgalio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_lstsize(t_stack *lst)
{
	int	i;

	i = 0;
	while (lst)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}

void	ft_free(t_stack *a, t_stack *b)
{
	t_stack	*tmp;

	while (a)
	{
		tmp = a;
		a = a->next;
		free(tmp);
	}
	while (b)
	{
		tmp = b;
		b = b->next;
		free(tmp);
	}
}

int	stack_create(t_stack **head, int value)
{
	t_stack	*new;
	t_stack	*tmp;

	new = (t_stack *)malloc(sizeof(t_stack));
	if (new == NULL)
		exit(1);
	tmp = *head;
	new->value = value;
	new->next = NULL;
	if (*head != NULL)
	{
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
	}
	else
		*head = new;
	return (0);
}
