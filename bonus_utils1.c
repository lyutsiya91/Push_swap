/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_utils1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgalio <sgalio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 17:07:21 by sgalio            #+#    #+#             */
/*   Updated: 2021/10/08 17:07:22 by sgalio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_memcmp(void *s1, void *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (n)
	{
		if (((unsigned char *)s1)[i] != ((unsigned char *)s2)[i])
			return (((unsigned char *)s1)[i] - ((unsigned char *)s2)[i]);
		i++;
		n--;
	}
	return (0);
}

int	ft_strncmp(char *s1, char *s2, size_t n)
{
	size_t	len1;
	size_t	len2;
	size_t	len;

	len1 = ft_strlen(s1) + 1;
	len2 = ft_strlen(s2) + 1;
	if (len1 > len2)
		len = len2;
	else
		len = len1;
	if (len > n)
		len = n;
	return (ft_memcmp(s1, s2, len));
}

int	ft_strcmp(char *s1, char *s2)
{
	size_t	len1;
	size_t	len2;
	size_t	len;

	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	if (len1 > len2)
		len = len1;
	else
		len = len2;
	return (ft_strncmp(s1, s2, len));
}
