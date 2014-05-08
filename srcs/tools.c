/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrachid <mrachid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/27 12:04:39 by mrachid           #+#    #+#             */
/*   Updated: 2014/03/27 16:04:40 by mrachid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh1.h"

int					recup_user(char **env, char *target)
{
	int				i;
	int				len;

	i = 0;
	len = ft_strlen(target);
	while (env[i])
	{
		if (ft_strncmp(target, env[i], len - 1) == 0)
			return (i);
		i++;
	}
	return (-1);
}

char				**recup_env(char **env)
{
	char		**tab;
	int			i;

	i = 0;
	while (env[i])
		i++;
	if (!(tab = (char **)malloc(sizeof(char *) * i + 1)))
		return (NULL);
	i = 0;
	while (env[i])
	{
		tab[i] = ft_strdup(env[i]);
		i++;
	}
	tab[i] = NULL;
	return (tab);
}

void				ft_remove_space(char *cmd)
{
	int				i;
	int				j;

	i = 0;
	j = 0;
	while (cmd[i])
	{
		while (cmd[j] == ' ')
			j++;
		cmd[i] = cmd[j];
		i++;
		j++;
	}
	cmd[i] = '\0';
}

char				*rec_target(char **env, char *target)
{
	int			index;
	int			c;
	int			t;
	int			len;
	char		*new;

	c = 0;
	index = 0;
	t = 0;
	len = ft_strlen(target);
	while (env[index])
	{
		if (ft_strncmp(env[index], target, len - 1) == 0)
			t = index;
		index++;
	}
	new = ft_strdup(env[t]);
	return (new);
}

int					ft_check_line(char *line, char **env)
{
	if (ft_strncmp(line, "cd", 2) == 0)
	{
		fct_cd(line, env);
		return (1);
	}
	if (ft_strncmp(line, "setenv ", 6) == 0)
	{
		fct_setenv(&line[7], env);
		return (1);
	}
	if (ft_strncmp(line, "unsetenv ", 8) == 0)
	{
		fct_unsetenv(line, env);
		return (1);
	}
	else
		return (0);
}
