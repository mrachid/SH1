/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrachid <mrachid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/27 15:04:18 by mrachid           #+#    #+#             */
/*   Updated: 2014/04/27 22:21:38 by mrachid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh1.h"

void				prompt(char **env)
{
	int				i;
	char			**name;

	if ((env[0]) == NULL)
		exit(0);
	i = recup_user(env, "USER");
	if (i != -1)
	{
		name = ft_strsplit(env[i], '=');
		if (name[1] != NULL)
		{
			ft_putstr(name[1]);
			write(1, " ~~> ", 5);
			return ;
		}
	}
	write(1, "mrachid$> ", 3);
}

void				boucle(pid_t father, char **path, char **envir, char **av)
{
	father = fork();
	if (father == 0)
		command(path, av, envir);
	else
		wait(&father);
}

int					main(int ac, char **av, char **env)
{
	pid_t		father;
	char		*line;
	char		**path;
	char		**envir;

	(void)ac;
	father = 0;
	envir = recup_env(env);
	path = recup_path(env);
	while (42)
	{
		prompt(envir);
		get_next_line(0, &line);
		if (*line == '\0')
			continue ;
		if (ft_strcmp(line, "exit") == 0 || ft_strncmp(line, "exit ", 4) == 0)
			exit(0);
		av = ft_strsplit(line, ' ');
		if (ft_check_line(line, envir) == 1)
			continue ;
		boucle(father, path, envir, av);
	}
	return (0);
}
