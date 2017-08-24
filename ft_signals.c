
#include "ft_minishell.h"

void	myhandle(int mysignal)
{
	if (mysignal == 2)
		shelloff(&saved);
	exit(0);
	signal(SIGINT,  myhandle);
}
