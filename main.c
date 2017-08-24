/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhanye <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/27 21:04:42 by akhanye           #+#    #+#             */
/*   Updated: 2017/08/24 13:54:09 by akhanye          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell.h"

static int		convert_string(char *templine, char **line)
{
	int		i;
	int		r;
	char	*temp;

	i = -1;
	(*line) = ft_strtrim(templine);
	temp = (*line);
	r = 0;
	while (temp[++i])
	{
		if (temp[i] == ' ' && r == 1)
			temp[i] = '?';
		else if (temp[i] == '"' && r == 0)
			r = 1;
		else if (temp[i] == '"' && r == 1)
			r = 0;
	}
	return (r);
}

static void		correct_string(char **cmd)
{
	int		i;
	int		c;
	int		n;
	char	*temp;
	char	*newstr;

	i = -1;
	c = 0;
	while (cmd[++i])
	{
		temp = cmd[i];
		newstr = ft_strnew(ft_strlen(temp) + 1);
		n = -1;
		c = 0;
		while (temp[++n])
		{
			if (temp[n] == '?')
				newstr[c++] = ' ';
			else if (temp[n] != '"')
				newstr[c++] = temp[n];
		}
		newstr[c] = '\0';
		free(cmd[i]);
		cmd[i] = newstr;
	}
}

static void		run_functions(char **cmd, char **arr, t_env *env)
{
	int		i;
	int		(*f[5])(char **, t_env *);

	f[0] = &ft_echo;
	f[1] = &ft_cd;
	f[2] = &ft_setenv;
	f[3] = &ft_unsetenv;
	f[4] = &ft_env;
	i = -1;
	if ((i = ft_inarray(cmd[0], arr)) != -1)
		f[i](cmd, env);
	else if (ft_run(cmd, env) == 1)
	{
		ft_putstr("zsh: command not found: ");
		ft_putendl(cmd[0]);
	}
	ft_freestrsplit(cmd);
}

static int		process_cmd(char *templine, char **arr, t_env *env)
{
	char	**cmd;
	char	*line;

	if (ft_strcmp(templine, "exit") == 0)
		return (-1);
	line = NULL;
	if (convert_string(templine, &line) == 1)
	{
		ft_putendl("Invalid Quote");
		return (free_return(0, &line));
	}
	if (ft_strlen(line) == 0)
		return (free_return(1, &line));
	fix_args(line);
	cmd = ft_strsplit(line, ' ');
	if (cmd == NULL)
		return (free_return(1, &line));
	correct_string(cmd);
	run_functions(cmd, arr, env);
	free(line);
	return (0);
}

int				main(void)
{
	char		*line;
	char		wdir[MAXWDIR];
	char		**arr;
	t_env		envv;

	envv.mem = NULL;
	if (!(arr = ft_strsplit(CMDS, '.')))
		return (1);
	getcwd(wdir, MAXWDIR);
	duplicate_environ(&envv);
	envv.wd = wdir;
	if (!init_ent(&envv, arr))
		return (0);
	line = NULL;
	while (TRUE)
	{
		ft_putstr("$> ");
		//get_next_line(0, &line);
		get_key_line(&line, &envv);
		if (process_cmd(line, arr, &envv) == -1)
		{
			ft_freestrsplit(arr);
			free(line);
			freeallmem(&envv.mem);
			ft_freestrsplit(envv.env);
			exit(0);
		}
		free(line);
	}
	return (0);
}
