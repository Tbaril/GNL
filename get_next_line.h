#ifndef GET_NEXT_LINE
# define GET_NEXT_LINE

# define BUFF_SIZE 4

# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>

char	*get_next_line(int fd);
int	ft_strlen(char *str);
char	*ft_strdup(char *str);
char	*ft_strjoin(char *s1, char *s2);

#endif
