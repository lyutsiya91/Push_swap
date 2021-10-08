/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgalio <sgalio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 16:56:46 by sgalio            #+#    #+#             */
/*   Updated: 2021/10/08 16:56:54 by sgalio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error_message(void)
{
	write(1, "Error\n", 6);
	exit(1);
}

void	check_error_message(void)
{
	write(1, "KO\n", 3);
	exit(1);
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	int		*order;

	if (argc < 2)
		exit(1);
	order = (int *)malloc(sizeof(int) * (argc - 1));
	if (order == NULL)
		exit(1);
	a = receive_args(argv, order);
	sort_array(order, argc - 1);
	if (check_order(a))
		exit(1);
	define_order(order, argc - 1, &a);
	if (argc <= 6)
		small_sort(&a, &b, argc - 1);
	else
	{
		sort_stack_a(&a, &b, argc - 1);
		sort_stack_b(&a, &b);
	}
	ft_free(a, b);
	free(order);
}
