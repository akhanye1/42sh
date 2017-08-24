
#include "ft_select.h"

int		ft_puts(int c)
{
	return (write(1, &c, 1));
}

void	k_action(int act, t_args **list)
{
	char	buf[20];
	char	*key;
	char	*ap;

	key = NULL;
	(*list)->selected = 0;
	ap = buf;
	if (act != KEY_UP && act != KEY_DOWN)
		return ;
	//tputs(tgetstr("ce", &ap), 1, ft_puts);
	if ((*list)->chosen)
		tputs(tgetstr("cm", &ap), 1, ft_puts);
	ft_putstr((*list)->name);
	if ((*list)->chosen)
		tputs(tgetstr("me", &ap), 1, ft_puts);
	if (act == KEY_UP)
	{
		if (!(*list)->prev)
			(*list) = (*list)->last;
		else
			(*list) = (*list)->prev;
	}
		//key = tgetstr("up", &ap);
	/*else if (act == KEY_RIGHT)
		key = tgetstr("nd", &ap);
	else if (act == KEY_LEFT)
		key = tgetstr("le", &ap);*/
	else if (act == KEY_DOWN)
	{
		if (!(*list)->next)
			(*list) = (*list)->first;
		else
			(*list) = (*list)->next;
	}
	(*list)->selected = 1;
	tputs(tgetstr("ce", &ap), 1, ft_puts);
	if ((*list)->selected)
		tputs(tgetstr("us", &ap), 1, ft_puts);
	ft_putstr((*list)->name);
	if ((*list)->selected)
		tputs(tgetstr("ue", &ap), 1, ft_puts);

		//key = tgetstr("do", &ap);
	/*if (key)
		tputs(key, 1, ft_puts);*/
}
