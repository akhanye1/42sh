/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhanye <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/27 23:40:00 by akhanye           #+#    #+#             */
/*   Updated: 2017/08/24 14:08:16 by akhanye          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MINISHELL_H
# define FT_MINISHELL_H
# include "libft/libft.h"
# include <term.h>
# include <signal.h>
# include <termcap.h>
# define CMDS "echo.cd.setenv.unsetenv.env"
# define MAXWDIR 10000
# define TERM_BUFFER 2048
# define KEY_UP 279165
# define KEY_DOWN 279166
# define KEY_LEFT 279168
# define KEY_RIGHT 279167
# define KEY_SPACE 32
# define KEY_BACKSPACE 127
# define KEY_DEL 279151126
# define KEY_HOME 279172
# define KEY_END 279170

typedef struct		s_mem
{
	char			*mem;
	char			**ppmem;
	struct s_mem	*next;
}					t_mem;

typedef struct		s_screen
{
	size_t			width;
	size_t			height;
	size_t			min_y;
	size_t			y;
	size_t			mw_width;
	size_t			padding;
}					t_screen;

typedef struct		s_hist
{
	char			*name;
	struct s_hist	*next;
	struct s_hist	*prev;
}					t_history;

typedef struct		s_env
{
	char			**env;
	char			*wd;
	struct s_mem	*mem;
	struct s_screen	screen;
	struct s_hist	*history;
	struct termios	term;
}					t_env;

struct termios		saved;


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
int					updateenv(char *cmp, char *newvar, t_env *env);
void				duplicate_new(t_env *env, char *val);
int					setnewenv(char *var, char *newvar, t_env *env);
void				fix_args(char *str);
int					shellon(t_env *env);
int					shelloff(struct termios *ptr);
void				myhandle(int mysignal);
void				initialise_screen(t_env *env);
int					get_key_line(char **line, t_env *env);
int					init_ent(t_env *env, char **arr);
void				k_action(int key, int *i, char *temp);
void				clear_line(void);
void				move_cursor(char dir);
int					ft_puts(int c);

#endif
