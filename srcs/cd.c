/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrachid <mrachid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/27 14:04:00 by mrachid           #+#    #+#             */
/*   Updated: 2014/03/27 17:04:02 by mrachid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh1.h"

static int			valid_cmd(char *path, char *target)
{
	if (*target == ' ' || *target == '\0')
		return (0);
	write(1, path, ft_strlen(path));
	ft_putendl(": command not found");
	return (1);
}

static char			*rec_value(char *full)
{
	int				i;
	char			*new_path;

	i = 0;
	while (full[i] != '/')
		i++;
	new_path = ft_strdup(&full[i]);
	return (new_path);
}

static void			ft_mod_pwd(char **bkp_env, char *line, char *pwd)
{
	int				index;
	char			*new;

	new = NULL;
	index = 0;
	if (pwd == NULL)
		new = ft_strjoin(line, getcwd(new, 1024));
	else
		new = ft_strjoin(line, pwd);
	while (bkp_env[index])
	{
		if (ft_strncmp(bkp_env[index], line, 2) == 0)
		{
			bkp_env[index] = NULL;
			bkp_env[index] = ft_strdup(new);
			break ;
		}
		index++;
	}
}

static void			ft_error_opening(char *path)
{
	ft_putstr(path);
	ft_putendl(": Not found or no rights, asshole!");
}

int					fct_cd(char *path, char **env)
{
	char			*full;
	char			*new_path;
	char			*old_pwd;
	int				a;

	old_pwd = NULL;
	old_pwd = getcwd(old_pwd, 1024);
	full = rec_target(env, "OLDPWD");
	new_path = ft_strdup(&path[3]);
	if (valid_cmd(path, &path[2]) == 1)
		return (0);
	if (*new_path == '-')
		new_path = rec_value(full);
	if (*new_path == '\0' || *new_path == '~')
		new_path = rec_value(rec_target(env, "HOME"));
	a = chdir(new_path);
	if (a == 0)
	{
		ft_mod_pwd(env, "PWD=", NULL);
		ft_mod_pwd(env, "OLDPWD=", old_pwd);
	}
	else
		ft_error_opening(path);
	return (a);
}
