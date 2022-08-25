#include "get_next_line.h"

int	full_line(char *str)
{
	int	i;

	i = 0;
	while (str[i] && str[i] == '\n')
		i++;
	while (str[i])
	{
		if (str[i] == '\n')
			return (i);
		i++;
	}
	return (0);
}

char	*extract_line(char *buff)
{
	int	i;
	int	j;
	char	*str;

	i = full_line(buff);
	j = 0;
	while (buff[j] && buff[j] == '\n')
		j++;
	str = (char *)malloc(sizeof(char) * (i - j));
	i = 0;
	while (j < i)
	{
		str[i] = buff[j];
		i++;
		j++;
	}
	str[j] = '\0';
	return (str);
}

char *get_next_line(int fd)
{
	static char	buff[BUFF_SIZE];
	char		*ret;

	ret = NULL;
	if (!buff)
		read(fd, buff, BUFF_SIZE);
	if (full_line(buff) > 0)
		ret = extract_line(buff);
	else	
	{
		while (full_line(buff) <= 0)
		{
			ret = ft_strjoin(ret, buff);
			read(fd, buff, BUFF_SIZE);
		}
		ret = ft_strjoin(ret, buff);
	}
	return (ret);
}

char	*ft_strjoin(char *str, char *buff)
{
	int	i;
	int	j;
	char	*ret;

	i = 0;
	j = 0;
	while (buff[j] && buff[j] != '\n')
		j++;
	if (!ret)
		return (ft_strdup(buff));
	ret = (char *)malloc(sizeof(char) * (ft_strlen(str) + j));
	j = 0;
	while (str[i])
	{
		ret[i] = str[i];
		i++;
	}
	while (buff[j] && buff[j] != '\n')
	{
		ret[i] = buff[j];
		i++;
		j++;
	}
	ret[i] = '\0';
	free(str);
	return (ret);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strdup(char *str)
{
	int	i;
	char	*ret;

	i = 0;
	ret = (char *)malloc(sizeof(char) * ft_strlen(str));
	while (str[i])
	{
		ret[i] = str[i];
		i++;
	}
	ret[i] = '\0';
	return (ret);
}
