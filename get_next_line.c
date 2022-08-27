#include "get_next_line.h"

int	full_line(char *str)
{
	int	i;

	i = 0;
//	printf("== start full line ==\n\n");
	while (str[i] && str[i] == '\n')
		i++;
	while (str[i])
	{
//		printf("searching line\n");
		if (str[i] == '\n')
		{
//			printf("\n== line found ==\n\n");
			return (i);
		}
		i++;
	}
//	printf("\n== not found ==\n\n");
	return (0);
}

void	erase_buff(char *buff)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (buff[j] && buff[j] == '\n')
		j++;
	while (buff[j] && buff[j] != '\n')
		j++;
	while (i < BUFF_SIZE)
	{
		if (j < BUFF_SIZE)
			buff[i] = buff[j];
		else
			buff[i] = '\0';
		i++;
		j++;
	}
}

char	*extract_line(char *buff)
{
	int	i;
	int	j;
	int	len;
	char	*str;

//	printf("== start of extract line ==\n\n");
	len = full_line(buff);
	j = 0;
	while (buff[j] && buff[j] == '\n')
		j++;
//	printf("allocation de str i = %i, j = %i\n", i, j);
	str = (char *)malloc(sizeof(char) * (len - j));
	i = 0;
//	printf("printing in str\n");
	while (buff[j] && buff[j] != '\n')
	{
//		printf("i = %i, j = %i\n", i, j);
		str[i] = buff[j];
		i++;
		j++;
	}
	str[j] = '\0';
	erase_buff(buff);
//	printf("end of extraction\n");
	return (str);
}

char *get_next_line(int fd)
{
	static char	buff[BUFF_SIZE];
	char		*ret;

	ret = NULL;
	if (buff[0] == '\0')
		read(fd, buff, BUFF_SIZE);
//	printf("%s\n", buff);
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
//	printf("== end ==\n");
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
