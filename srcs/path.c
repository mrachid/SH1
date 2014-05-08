/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrachid <mrachid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/27 22:04:25 by mrachid           #+#    #+#             */
/*   Updated: 2014/04/27 22:04:26 by mrachid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh1.h"

static char				**init_path(char *str)
{
	char			**tab_path;
	char			*mem;
	int				i;

	i = 0;
	tab_path = NULL;
	mem = ft_strchr(str, '/');
	tab_path = ft_strsplit(mem, ':');
	while (tab_path[i])
	{
		tab_path[i] = ft_strjoin(tab_path[i], "/");
		i++;
	}
	return (tab_path);
}

char					**recup_path(char **env)
{
	int				i;
	char			**path;

	i = 0;
	while (env[i])
	{
		if (ft_strstr(env[i], "PATH"))
			path = init_path(env[i]);
		i++;
	}
	return (path);
}
