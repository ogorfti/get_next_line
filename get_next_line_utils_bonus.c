/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogorfti <ogorfti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 13:24:28 by ogorfti           #+#    #+#             */
/*   Updated: 2022/11/05 20:06:13 by ogorfti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != '\0')
		i++;
	return (i);
}

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;
	char	*cnv_d;
	char	*cnv_s;

	cnv_d = dst;
	cnv_s = (void *)src;
	i = 0;
	if (cnv_d == NULL && cnv_s == NULL)
		return (NULL);
	while (i < n)
	{
		cnv_d[i] = cnv_s[i];
		i++;
	}
	return (cnv_d);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*res;
	size_t	len_s1;
	size_t	len_s2;

	if (!s1 || !s2)
		return (NULL);
	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	res = malloc(len_s2 + len_s1 + 1);
	if (res)
	{
		ft_memcpy(res, s1, len_s1);
		ft_memcpy(res + len_s1, s2, len_s2 + 1);
	}
	free (s1);
	return (res);
}

void	ft_bzero(void *s, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		((char *)s)[i] = '\0';
		i++;
	}
}

void	*ft_calloc(size_t count, size_t size)
{
	size_t	i;
	void	*ptr;

	i = 0;
	if (count >= SIZE_MAX && size >= SIZE_MAX)
		return (NULL);
	ptr = malloc(count * size);
	if (!ptr)
		return (NULL);
	else
	{
		ft_bzero(ptr, count * size);
		return (ptr);
	}
	return (0);
}
