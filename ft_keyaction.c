
#include "ft_minishell.h"

int		ft_puts(int c)
{
	return (write(1, &c, 1));
}

static void	insert_key(char *append)
{
	char *key;
	char buf[20];
	char *ap;

	ft_bzero(buf, 20);
	ap = buf;
	key = NULL;	
	key = tgetstr("ce", &ap);
	if (key)
		tputs(key, 1, ft_puts);
	key = NULL;
	key = tgetstr("sc", &ap);
	if (key)
		tputs(key, 1, ft_puts);
	ft_putstr(append);
	key = NULL;
	key = tgetstr("rc", &ap);
	if (key)
		tputs(key, 1, ft_puts);
	key = NULL;
	key = tgetstr("nd", &ap);
	if (key)
		tputs(key, 1, ft_puts);

}

static void	clear_key(char *append)
{
	char *key;
	char buf[20];
	char *ap;

	ft_bzero(buf, 20);
	ap = buf;
	key = NULL;
	key = tgetstr("le", &ap);
	if (key)
		tputs(key, 1, ft_puts);
	key = NULL;	
	key = tgetstr("ce", &ap);
	if (key)
		tputs(key, 1, ft_puts);
	key = NULL;
	key = tgetstr("sc", &ap);
	if (key)
		tputs(key, 1, ft_puts);
	ft_putstr(append);
	key = NULL;
	key = tgetstr("rc", &ap);
	if (key)
		tputs(key, 1, ft_puts);
}

static void	del_key(char *append)
{
	char *key;
	char buf[20];
	char *ap;

	ft_bzero(buf, 20);
	ap = buf;
	key = NULL;	
	key = tgetstr("ce", &ap);
	if (key)
		tputs(key, 1, ft_puts);
	key = NULL;
	key = tgetstr("sc", &ap);
	if (key)
		tputs(key, 1, ft_puts);
	ft_putstr(append);
	key = NULL;
	key = tgetstr("rc", &ap);
	if (key)
		tputs(key, 1, ft_puts);
}

static void	input_key(int act, int *i, char *temp)
{
	char *copy;

	if (!temp[*i])
	{
		temp[*i] = act;
		ft_putchar(act);
	}
	else
	{
		copy = ft_strdup(temp + *i);
		temp[*i] = act;
		ft_strcpy(temp + (*i + 1), copy);
		insert_key(temp + *i);
	}
	(*i)++;
}

static void	del_left(char *temp, int *i)
{
	char	*copy;

	if (!temp[*i])
	{
		temp[*i - 1] = '\0';
		move_cursor('l');
		clear_line();
	}
	else
	{
		copy = temp + (*i);
		ft_strcpy(temp + (*i - 1), copy);
		clear_key(temp + (*i - 1));
	}
	(*i)--;
}

static void	del_right(char *temp, int *i)
{
	char	*copy;

	if (temp[*i])
	{
		copy = temp + (*i + 1);
		ft_strcpy(temp + *i, copy);
		del_key(temp + *i);
	}
}

void	k_action(int act, int *i, char *temp)
{
	char	buf[20];
	char	*key;
	char	*ap;

	key = NULL;
	ap = buf;
	if (ft_isprint(act))
		input_key(act, i, temp);
	else if (act == KEY_BACKSPACE && *i > 0)
		del_left(temp, i);
	else if (act == KEY_DEL && *i < (int)ft_strlen(temp))
		del_right(temp, i);

	/*else if (act != KEY_UP && act != KEY_DOWN)
	  return ;
	  if (act == KEY_UP)
	  {
	  if (!(*list)->prev)
	  (*list) = (*list)->last;
	  else
	  (*list) = (*list)->prev;
	  }
	//key = tgetstr("up", &ap);*/
	  else if (act == KEY_RIGHT && *i < (int)ft_strlen(temp))
	  {
		  key = tgetstr("nd", &ap);
		  (*i)++;
	  }
	  else if (act == KEY_LEFT && *i > 0)
	  {
		  key = tgetstr("le", &ap);
		  (*i)--;
	  }
	  /*else if (act == KEY_DOWN)
		{
		if (!(*list)->next)
		(*list) = (*list)->first;
		else
		(*list) = (*list)->next;
		}
		(*list)->selected = 1;*/

	  //key = tgetstr("do", &ap);
	  if (key)
		  tputs(key, 1, ft_puts);
}
