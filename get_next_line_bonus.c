/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogorfti <ogorfti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 13:24:31 by ogorfti           #+#    #+#             */
/*   Updated: 2022/11/05 20:07:52 by ogorfti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_strchr(char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != (char)c)
	{
		if (s[i] == '\0')
		{
			return (0);
		}
		i++;
	}
	return ((char *)&s[i]);
}

char	*new_backup(char *oldline)
{
	char	*new_backup;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (oldline[i] != '\n' && oldline[i])
		i++;
	if (!oldline[i])
	{
		free(oldline);
		return (NULL);
	}
	i++;
	new_backup = malloc(ft_strlen(oldline) - i + 1);
	if (!new_backup)
	{
		free (oldline);
		return (NULL);
	}
	while (oldline[i])
		new_backup[j++] = oldline[i++];
	new_backup[j] = '\0';
	free(oldline);
	return (new_backup);
}

char	*get_befor_line(char *s)
{
	char	*arr;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (s[i] != '\n' && s[i])
		i++;
	if (s[i] == '\n')
		i++;
	arr = malloc(i + 2);
	if (!arr)
		return (NULL);
	while (j < i)
	{
		arr[j] = s[j];
		j++;
	}
	arr[j] = '\0';
	if (*arr == '\0')
	{
		free (arr);
		arr = NULL;
	}
	return (arr);
}

char	*ft_join(int fd, char *joiner)
{
	char	*buffer;
	int		checker;
	int		i;

	if (!joiner)
		joiner = ft_calloc(1, 1);
	i = 0;
	checker = 1;
	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (0);
	while (checker != 0)
	{
		checker = read(fd, buffer, BUFFER_SIZE);
		if (checker == -1)
			break ;
		buffer[checker] = '\0';
		joiner = ft_strjoin(joiner, buffer);
		if (ft_strchr(joiner, '\n'))
			break ;
	}
	free(buffer);
	return (joiner);
}

char	*get_next_line(int fd)
{
	char		*curr;
	char		*line;
	static char	*backup[OPEN_MAX];

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	curr = ft_join(fd, backup[fd]);
	if (!curr)
		return (NULL);
	line = get_befor_line(curr);
	backup[fd] = new_backup(curr);
	return (line);
}

// int main()
// {
// 	int fd;

// 	fd = open("fd.txt", O_RDONLY);
// 	printf("%s", get_next_line(fd));
// 	printf("%s", get_next_line(fd));
// 	printf("%s", get_next_line(fd));
// 	printf("%s", get_next_line(fd));
// 	printf("%s", get_next_line(fd));
// 	printf("%s", get_next_line(fd));
// 	printf("%s", get_next_line(fd));
// }