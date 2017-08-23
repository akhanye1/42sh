
#include "ft_minishell.h"

void fix_args(char *str)
{
	int	i;
	int	q;

	i = -1;
	q = 0;
	while (str[++i])
	{
		if ((str[i] == '\t' || str[i] == '\f' || str[i] == '\v' ||
				str[i] == '\n' || str[i] == '\f' || str[i] == '\r') &&
				q == 0)
			str[i] = ' ';
		if (str[i] == '"')
			q = (q) ? 0 : 1;
	}
}
