
#include "ft_minishell.h"

void	clear_line(void)
{
	char	*key;
	char	buf[20];
	char	*ap;

	ap = buf;
	key = NULL;
	key = tgetstr("ce", &ap);
	if (key)
		tputs(key, 1, ft_puts);
}

void	move_cursor(char dir)
{
	char	*key;
	char	buf[20];
	char	*ap;

	key = NULL;
	ap = buf;
	if (dir == 'l')
		key = tgetstr("le", &ap);
	else if (dir == 'r')
		key = tgetstr("nd", &ap);
	if (key)
		tputs(key, 1, ft_puts);
}
