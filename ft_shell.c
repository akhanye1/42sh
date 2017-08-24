
#include "ft_minishell.h"

int		shelloff(struct termios *ptr)
{
	return (tcsetattr(STDIN_FILENO, TCSANOW, ptr) != -1);
}

int		shellon(t_env *env)
{
	char	buff[TERM_BUFFER];

	if (!isatty(STDIN_FILENO) || tgetent(buff, get_envvalue("TERM", env)) < 0 ||
			tcgetattr(0, env->term) == -1)
		return (0);
	env->term->c_lflag &= ~(ICANON | ECHO);
	env->term->c_cc[VMIN] = 1;
	env->term->c_cc[VTIME] = 0;
	if (tcsetattr(STDIN_FILENO, TCSAFLUSH, env->term) == -1)
		return (0);
	return (1);
}
