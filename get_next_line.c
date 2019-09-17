/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnancy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/18 10:43:55 by fnancy            #+#    #+#             */
/*   Updated: 2019/04/18 10:43:55 by fnancy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft/libft.h"

void				realoc_str(char **buf_fd, char *buf)
{
	char	*tmp_line;

	if (!((*buf_fd)))
		(*buf_fd) = ft_strnew(1);
	tmp_line = ft_strjoin((*buf_fd), buf);
	free((*buf_fd));
	(*buf_fd) = tmp_line;
}

int					write_line(char **buf_fd, char **line)
{
	char	*help;
	int		ind;

	if (!(ft_strchr(*buf_fd, '\n')))
	{
		(*line) = ft_strdup((*buf_fd));
		ft_strdel(&(*buf_fd));
		if (ft_strlen((*line)) > 0)
			return (1);
		return (0);
	}
	ind = ft_strchr((*buf_fd), '\n') - (*buf_fd);
	if (ind == 0)
		(*line) = ft_strnew(1);
	else if (!((*line) = ft_strsub((*buf_fd), 0, ind)))
		return (0);
	if (!(help = ft_strsub((*buf_fd), ind + 1, ft_strlen((*buf_fd)))))
		return (0);
	free((*buf_fd));
	(*buf_fd) = help;
	return (1);
}

int					get_next_line(const int fd, char **line)
{
	char static		*buf_fd[10000];
	char			buf[BUFF_SIZE + 1];
	int				red;

	red = 0;
	if (fd < 0 || !line || read(fd, buf, 0))
		return (-1);
	if (!(buf_fd[fd]) || !(ft_strchr(buf_fd[fd], '\n')))
	{
		while ((red = read(fd, buf, BUFF_SIZE)) > 0)
		{
			buf[red] = '\0';
			realoc_str(&buf_fd[fd], buf);
			if (ft_strchr(buf, '\n') != NULL)
				break ;
		}
	}
	if (red == 0 && !(buf_fd[fd]))
	{
		free(buf_fd[fd]);
		(*line) = NULL;
		return (0);
	}
	return (write_line(&buf_fd[fd], &(*line)));
}
