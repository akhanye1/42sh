/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhanye <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/27 23:40:00 by akhanye           #+#    #+#             */
/*   Updated: 2017/07/30 17:58:02 by akhanye          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MINISHELL_H
# define FT_MINISHELL_H
# include "libft/libft.h"
# define CMDS "echo.cd.setenv.unsetenv.env"
# define MAXWDIR 1000

typedef struct		s_mem
{
	char			*mem;
	char			**ppmem;
	struct s_mem	*next;
}					t_mem;

typedef struct		s_env
{
	char			**env;
	char			*wd;
	struct s_mem	*mem;
}					t_env;

enum				{FALSE, TRUE};
int					ft_echo(char **cmd, t_env *env);
int					ft_cd(char **cmd, t_env *env);
int					ft_setenv(char **cmd, t_env *env);
int					ft_unsetenv(char **cmd, t_env *env);
int					ft_env(char **cmd, t_env *env);
int					ft_run(char **cmd, t_env *env);
void				add_tostack(t_mem **mem, char *tmem, char **ptemp);
void				remove_stack(t_mem **mem, char *tmem);
void				freeallmem(t_mem **mem);
int					free_return(int num, char **line);
void				duplicate_environ(t_env *env);
char				*get_envvalue(char *var, t_env *envv);
int				updateenv(char *cmp, char *newvar, t_env *env);
void				duplicate_new(t_env *env, char *val);
int				setnewenv(char *var, char *newvar, t_env *env);
void			fix_args(char *str);

#endif
