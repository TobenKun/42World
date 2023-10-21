/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangshin <zxcv1867@naver.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 22:36:49 by sangshin          #+#    #+#             */
/*   Updated: 2023/10/22 01:28:20 by sangshin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*
int	main(void)
{
	int fd;

	fd = open("./test.txt", O_RDONLY);
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
}
*/
char	*get_next_line(int fd)
{
	static char	*strings[257];

	if (fd < 0 || fd > 256)
		return (0);
	if (strings[fd] == 0)
		strings[fd] = reader(strings[fd], fd);
	if (strings[fd] == 0)
		return (0);
	return (cutter_cal(&strings[fd]));
}

char	*reader(char *string, int fd)
{
	char	buf[BUFFER_SIZE + 1];
	long	read_size;

	read_size = 0;
	while (read_size <= BUFFER_SIZE)
		buf[read_size++] = 0;
	while (read_size > 0)
	{
		read_size = read(fd, buf, BUFFER_SIZE);
		if (read_size <= 0)
			break ;
		string = join(string, buf);
	}
	if (read_size < 0 && string)
	{
		free(string);
		string = 0;
	}
	return (string);
}

char	*join(char *string, char *buf)
{
	int		i;
	char	*tmp;

	i = 0;
	if (string == 0)
	{
		string = (char *)malloc(1);
		string[0] = 0;
	} // free 해주려면 동적할당해야됨 ㅋㅋ
	while (string[i])
		i++;
	tmp = (char *)malloc(i + BUFFER_SIZE + 1);
	i = -1;
	while (string[++i])
		tmp[i] =string[i];
	while (*buf)
		tmp[i++] = *buf++;
	tmp[i] = 0;
	free(string);
	return (tmp);
}

char	*cutter_cal(char **string)
{
	int		i;
	int		j;
	char	*tmp;

	i = 0;
	j = -1;
	while ((*string)[i] != 10 && (*string)[i])
		i++;
	tmp = (char *)malloc(i + 2); // 개행 하나 널 하나 총 2개
	while (++j <= i)
		tmp[j] = (*string)[j];
	tmp[j] = 0;
	if ((*string)[i] == 0)
	{
		free(*string);
		if (j == 1)
		{
			free(tmp);
			return (0);
		}
		*string = 0;
	}
	else
		*string = rose_knife(*string, i + 1);
	return (tmp);
}

char	*rose_knife(char *string, int i)
{
	int		len;
	int		j;
	char	*tmp;

	len = 0;
	j = -1;
	while (string[i + len])
		len++;
	tmp = malloc(len + 1);
	while (++j <= len)
		tmp[j] = string[i + j];
	free(string);
	return (tmp);
}
