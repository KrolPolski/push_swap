/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rboudwin <rboudwin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 18:24:49 by rboudwin          #+#    #+#             */
/*   Updated: 2023/11/29 20:25:41 by rboudwin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

void	free_and_null(void *ptr)
{
	free(ptr);
	ptr = NULL;
}

char	*ft_read_as_needed(int fd, char *stash, t_gnl *gnl)
{
	while (!ft_strchr(stash, '\n') && gnl->bytes_read != 0)
	{
		gnl->bytes_read = read(fd, gnl->buffer, BUFFER_SIZE);
		if (gnl->bytes_read == -1 || gnl->bytes_read == 0)
		{
			if (gnl->bytes_read == -1)
				free_and_null(stash);
			if (gnl->bytes_read == 0)
				return (stash);
			return (NULL);
		}
		gnl->buffer[gnl->bytes_read] = '\0';
		if (stash == NULL)
		{
			stash = malloc(1);
			if (!stash)
				return (NULL);
			stash[0] = '\0';
		}
		gnl->ptr_parking = stash;
		stash = ft_strjoin(stash, gnl->buffer);
		free(gnl->ptr_parking);
		gnl->ptr_parking = NULL;
	}
	return (stash);
}

char	*ft_fetch_line(char *stash, t_gnl *gnl)
{
	if (!stash)
		return (NULL);
	gnl->i = 0;
	while (stash[gnl->i] != '\0' && stash[gnl->i] != '\n')
		gnl->i++;
	if (stash[gnl->i] == '\n')
		gnl->i++;
	gnl->line = malloc(gnl->i + 1);
	if (gnl->line == NULL)
	{
		return (NULL);
	}
	gnl->k = 0;
	while (gnl->k < gnl->i)
	{
		gnl->line[gnl->k] = stash[gnl->k];
		gnl->k++;
	}
	gnl->line[gnl->k] = '\0';
	return (gnl->line);
}

char	*ft_trim_stash(char *stash, t_gnl *gnl)
{
	if (!gnl->line)
	{
		free(stash);
		stash = NULL;
		return (NULL);
	}
	gnl->strchr_result = ft_strchr(stash, '\n');
	if (!gnl->strchr_result)
	{
		free_and_null(stash);
		return (NULL);
	}
	else if (ft_strchr(stash, '\n') && ft_strlen(gnl->strchr_result) == 1)
	{
		free_and_null(stash);
		return (NULL);
	}
	{
		gnl->ptr_parking = stash;
		stash = ft_substr(stash, (gnl->strchr_result - stash) + 1,
				ft_strlen(stash));
		free_and_null(gnl->ptr_parking);
		return (stash);
	}
}

char	*get_next_line(int fd)
{
	static char	*stashes[1024];
	t_gnl		gnl;

	if (fd < 0 || fd > 1023 || BUFFER_SIZE <= 0)
		return (NULL);
	gnl.ptr_parking = NULL;
	gnl.bytes_read = 1;
	if (!ft_strchr(stashes[fd], '\n'))
	{
		gnl.buffer = malloc(BUFFER_SIZE + 1);
		if (!gnl.buffer)
		{
			if (stashes[fd] != NULL)
			{
				free(stashes[fd]);
				stashes[fd] = NULL;
			}
			return (NULL);
		}
		stashes[fd] = ft_read_as_needed(fd, stashes[fd], &gnl);
		free_and_null(gnl.buffer);
	}
	gnl.line = ft_fetch_line(stashes[fd], &gnl);
	stashes[fd] = ft_trim_stash(stashes[fd], &gnl);
	return (gnl.line);
}
