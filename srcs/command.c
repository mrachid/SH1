/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrachid <mrachid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/27 10:04:07 by mrachid           #+#    #+#             */
/*   Updated: 2014/02/27 15:04:08 by mrachid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh1.h"

static char		*error(char **env, char *av)
{
	char	*error;
	int		i;

	i = 0;
	while (env[i])
	{
		if (ft_strstr(env[i], "SHELL"))
			error = ft_strrchr(env[i], '/');
		i++;
	}
	ft_putstr("Error");
	ft_putstr(": ");
	ft_putstr("command not found: ");
	ft_putendl(av);
	exit(1);
	return (NULL);
}

char			*command(char **path, char **av, char **env)
{
	int		i;

	i = 0;
	execve(av[0], av, env);
	while (path[i])
	{
		execve(ft_strjoin(path[i], av[0]), av, env);
		i++;
	}
	error(env, av[0]);
	return (NULL);
}
