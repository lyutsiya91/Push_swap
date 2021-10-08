/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgalio <sgalio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 17:07:33 by sgalio            #+#    #+#             */
/*   Updated: 2021/10/08 17:08:51 by sgalio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	execute_command(char *line, t_stack **a, t_stack **b)
{
	if (ft_strcmp(line, "pa") == 0)
		ft_pa(a, b);
	else if (ft_strcmp(line, "pb") == 0)
		ft_pb(a, b);
	else if (ft_strcmp(line, "ra") == 0)
		ft_ra(a);
	else if (ft_strcmp(line, "rra") == 0)
		ft_rra(a);
	else if (ft_strcmp(line, "rb") == 0)
		ft_rb(b);
	else if (ft_strcmp(line, "rrb") == 0)
		ft_rrb(b);
	else if (ft_strcmp(line, "rrr") == 0)
		ft_rrr(a, b);
	else if (ft_strcmp(line, "sa") == 0)
		ft_sa(a);
	else if (ft_strcmp(line, "sb") == 0)
		ft_sb(b);
	else
		error_message();
}

char	*ft_strnew(int size)
{
	char	*str;

	str = (char *)malloc(sizeof(char) * (size + 1));
	if (!str)
		return (NULL);
	str[size] = '\0';
	return (str);
}

int	get_next_line(char **line)
{
	char	*buf;
	int		read_size;

	buf = (char *)malloc(sizeof(char) * 2);
	if (!line || !buf || read(0, buf, 0) < 0)
		return (-1);
	*line = ft_strnew(0);
	read_size = 1;
	while (read_size != 0)
	{
		read_size = read(0, buf, 1);
		if (buf[0] == '\n')
		{
			free(buf);
			return (1);
		}
		buf[read_size] = '\0';
		*line = ft_strjoin(*line, buf);
	}
	free(buf);
	return (0);
}

void	read_command(t_stack **a, t_stack **b)
{
	char	*line;

	line = NULL;
	while (get_next_line(&line))
	{
		execute_command(line, a, b);
		free(line);
		line = NULL;
	}
	if (line)
	{
		free(line);
		line = NULL;
	}
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
	read_command(&a, &b);
	if (check_order(a) && ft_lstsize(b) == 0)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	ft_free(a, b);
	free(order);
}
