/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh1.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrachid <mrachid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/27 22:10:46 by mrachid           #+#    #+#             */
/*   Updated: 2014/04/27 22:10:48 by mrachid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SH1_H
# define SH1_H

# include "../libft/includes/libft.h"

char		*command(char **path, char **av, char **bkp);
char		**recup_path(char **env);
int			fct_cd(char *path, char **bkp_env);
void		fct_setenv(char *line, char **env);
void		fct_unsetenv(char *line, char **env);
char		*rec_target(char **bkp_env, char *target);
char		**recup_env(char **env);
int			ft_check_line(char *line, char **env);
void		ft_remove_space(char *cmd);
int			recup_user(char **env, char *focus);

#endif
