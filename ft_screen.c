
#include "ft_minishell.h"

/*static void	get_pos(t_env *env)
{
	int		a;
	int		i;
	char	buff[4];

	ft_putendl("pos debug 1");
	write(1, "\033[6n", 4);
	ft_putendl("pos debug 2");
	i = read(1, buff, 4);
	ft_putendl("pos debug 3");
	buff[i] = '\0';
	i = -1;
	a = 0;
	ft_putendl("pos debug 1");
	while (buff[++i])
	{
		if (buff[i] >= 48 && buff[i] <= 57)
		{
			env->screen.min_y = ft_atoi(&buff[i]);
			return ;
		}
	}
	ft_putendl("pos debug 2");
}*/

void		initialise_screen(t_env *env)
{
	env->screen.width = tgetnum("co");
	env->screen.height = tgetnum("li");
	env->screen.mw_width = 0;
	env->screen.padding = 0;
	//get_pos(env);
}
