/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unsetenv.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrachid <mrachid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/27 10:04:45 by mrachid           #+#    #+#             */
/*   Updated: 2014/02/27 15:04:50 by mrachid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh1.h"

static int			ft_is_valid_unsetenv(char *cmd)
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
	if (e == 0 && i >= 1)
		return (0);
	return (1);
}

static char			*ft_check_unsetenv(char *line)
{
	char			*new;

	while (*line == ' ' && *line)
		line++;
	new = ft_strdup(line);
	return (new);
}

static void			ft_do_unsetenv(char *focus, char **env)
{
	int				i;
	int				t;
	int				len;

	i = 0;
	t = 0;
	len = ft_strlen(focus);
	while (env[i])
	{
		if (ft_strncmp(focus, env[i], len - 1) == 0)
		{
			t = i;
		}
		i++;
	}
	ft_strclr(env[t]);
}

void				fct_unsetenv(char *line, char **env)
{
	char			*new;
	char			**tab;

	new = ft_check_unsetenv(line);
	if (ft_is_valid_unsetenv(new) == 1)
	{
		ft_putendl("please type : unsetenv 'NAME'");
		return ;
	}
	tab = ft_strsplit(new, ' ');
	ft_do_unsetenv(tab[1], env);
}
