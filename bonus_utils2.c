/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgalio <sgalio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 17:07:27 by sgalio            #+#    #+#             */
/*   Updated: 2021/10/08 17:07:28 by sgalio           ###   ########.fr       */
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

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (str[len] != '\0')
	{
		len++;
	}
	return (len);
}

void	ft_strcpy(char *dst, char *src)
{
	size_t	i;

	i = 0;
	if (!src)
		return ;
	while (src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*str;
	size_t	len1;
	size_t	len2;

	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	str = (char *)malloc(sizeof(char) * (len1 + len2 + 1));
	if (str != ((void *)0))
	{
		ft_strcpy(str, s1);
		ft_strcpy(str + len1, s2);
		free((char *)s1);
		return (str);
	}
	else
		return ((void *)0);
}
