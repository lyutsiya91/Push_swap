/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   receive_args.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgalio <sgalio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 16:57:57 by sgalio            #+#    #+#             */
/*   Updated: 2021/10/08 16:58:00 by sgalio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_isdigit(int c)
{
	if (c >= 48 && c <= 57)
		return (1);
	else
		return (0);
}

int	define_sign(const char *str)
{
	int	sign;

	sign = 1;
	if (*str == '-')
		sign = -1;
	return (sign);
}

long long	ft_convert(const char *str, int sign, long long number)
{
	if (*str && ft_isdigit(*str))
		number = (number * 10) + ((int)*str - '0');
	if ((number - 1 > INT_MAX && sign == -1)
		|| (number > INT_MAX && sign == 1))
		error_message();
	return (number);
}

int	ft_atoi(const char *str)
{
	int		sign;
	long	number;

	number = 0;
	sign = 1;
	while (*str && ((*str >= 9 && *str <= 13) || *str == ' '))
		str++;
	if (*str == '+' || *str == '-')
	{
		sign = define_sign(str);
		str++;
	}
	if (ft_isdigit(*str))
	{
		while (*str && ft_isdigit(*str))
		{
			number = ft_convert(str, sign, number);
			str++;
		}
	}
	else
		error_message();
	return (sign * number);
}

t_stack	*receive_args(char **argv, int *order)
{
	int		i;
	int		n;
	long	tmp;
	t_stack	*a;

	i = 0;
	a = NULL;
	while (argv[i + 1])
	{
		tmp = ft_atoi((const char *)argv[i + 1]);
		n = 0;
		while (n < i)
		{
			if (tmp == order[n++])
				error_message();
		}
		order[i] = tmp;
		stack_create(&a, tmp);
		i++;
	}
	return (a);
}
