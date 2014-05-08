/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setenv.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrachid <mrachid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/27 22:04:32 by mrachid           #+#    #+#             */
/*   Updated: 2014/04/27 22:04:34 by mrachid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh1.h"

static int			ft_is_valid_setenv(char *cmd)
{
	int				i;
	int				t;
	int				e;

	i = 0;
	t = 0;
	e = 0;
	while (cmd[i])
	{
		if (cmd[i] == ' ')
			t++;
		while (cmd[i] == ' ')
			i++;
		if (cmd[i] == '\0')
			return (1);
		if (cmd[i] == '=')
			e++;
		i++;
	}
	if (e == 1 && t > 1)
		return (0);
	return (1);
}

static char			*ft_check_setenv(char *line)
{
	char			*new;

	while (*line == ' ' && *line)
		line++;
	new = ft_strdup(line);
	return (new);
}

static void			ft_mod_env(char *focus, char *cmd, char **env)
{
	int				i;
	int				t;
	int				len;

	i = 0;
	t = 0;
	len = ft_strlen(focus);
	while (env[i])
	{
		if (ft_strncmp(focus, env[i], (len - 1)) == 0)
		{
			t = i;
		}
		i++;
	}
	env[t] = ft_strdup(NULL);
	env[t] = ft_strdup(cmd);
}

static void			ft_do_setenv(char *cmd, char **env)
{
	char			**set;

	set = ft_strsplit(cmd, '=');
	ft_mod_env(set[0], cmd, env);
}

void				fct_setenv(char *line, char **env)
{
	char			*new;

	new = NULL;
	new = ft_check_setenv(line);
	if (ft_is_valid_setenv(new) == 1)
	{
		ft_putendl("please enter : setenv 'NAME' = 'valeur'");
		return ;
	}
	ft_remove_space(new);
	ft_do_setenv(new, env);
}
