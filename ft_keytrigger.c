
#include "ft_minishell.h"

static int      get_all_digits(char *buff)
{
	int     len;
	int     i;
	char    num;

	len = 0;
	i = -1;
	while (buff[++i])
	{
		num = buff[i];
		while (num > 0)
		{
			len++;
			num /= 10;
		}
	}
	len--;
	return (len);
}

static int      get_value(char *buff)
{
	int     i;
	int     c;
	char    str[50];
	char    *temp;

	temp = ft_strdup(buff);
	i = -1;
	c = get_all_digits(buff);
	ft_bzero(str, 50);
	while (temp[++i])
		;
	while (i-- > 0)
	{
		while (temp[i] > 0)
		{
			str[c--] = (temp[i] % 10) + '0';
			temp[i] /= 10;
		}
	}
	free(temp);
	return (ft_atoi(str));
}

int		get_key_line(char **line, t_env *env)
{
	char	buf[7];
	char	temp[MAXWDIR];
	int		len;
	int		key;
	int		i;

	if (!env->mem)
	{
	}
	i = 0;
	ft_bzero(temp, MAXWDIR);
	while (1)
	{
		ft_bzero(buf, 7);
		len = read(0, buf, 7);
		buf[len] = '\0';
		key = get_value(buf);
		if (key == 27 || key == 10)
			break ;
		k_action(key, &i, temp);
	}
	if (key == 10)
	{
		(*line) = ft_strdup(temp);
		ft_putline();
	}
	return (1);
}
