
#include "ft_minishell.h"

static int	initialize_shell(t_env *env)
{
	return (shellon(env));
}

int		init_ent(t_env *env, char **arr)
{
	char	buff[5];

	if (tgetent(buff, get_envvalue("TERM", &env)) <= 0)
	{
		ft_freestrsplit(env->env);
		ft_freestrsplit(arr);
		return (0);
	}
	// TODO initialize signals here
	
	initialise_screen(&env);	
	initialize_shell(&env);
	return (1);
}
