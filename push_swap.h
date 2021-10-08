/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgalio <sgalio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 17:06:44 by sgalio            #+#    #+#             */
/*   Updated: 2021/10/08 17:06:47 by sgalio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <limits.h>

typedef struct s_stack
{
	int				value;
	int				order;
	struct s_stack	*next;
}					t_stack;

int		ft_isdigit(int c);
int		ft_atoi(const char *str);
t_stack	*receive_args(char **argv, int *order);

int		stack_create(t_stack **head, int value);
int		ft_lstsize(t_stack *lst);
void	ft_free(t_stack *a, t_stack *b);

void	sort_array(int *order, int number);
int		check_order(t_stack *a);
void	define_order(int *order, int number, t_stack **a);

void	ft_sort_three(t_stack **a);
void	ft_sort_five(t_stack **a, t_stack **b, int number);
void	small_sort(t_stack **a, t_stack **b, int number);

void	sort_stack_a(t_stack **a, t_stack **b, int number);
void	sort_stack_b(t_stack **a, t_stack **b);
int		ft_find_max(t_stack *a);
int		define_position(t_stack *b, int max);

void	ft_sa(t_stack **a);
void	ft_sb(t_stack **b);
void	ft_pa(t_stack **a, t_stack **b);
void	ft_pb(t_stack **a, t_stack **b);
void	ft_ra(t_stack **a);
void	ft_rra(t_stack **a);
void	ft_rb(t_stack **b);
void	ft_rrb(t_stack **b);
void	ft_rrr(t_stack **a, t_stack **b);

void	execute_command(char *line, t_stack **a, t_stack **b);
void	read_command(t_stack **a, t_stack **b);
int		get_next_line(char **line);
char	*ft_strnew(int size);
int		ft_strlen(char *str);
char	*ft_strjoin(char *str1, char *str2);
int		ft_strcmp(char *s1, char *s2);

void	error_message(void);
void	check_error_message(void);

#endif
