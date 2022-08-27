#include "get_next_line.h"

int	main()
{
	int	fd;
	char	*line;

	fd = open("test.txt", O_RDONLY);
	line = get_next_line(fd);
	printf("line is : %s\n", line);
	line = get_next_line(fd);
	printf("line is : %s\n", line);
	close(fd);
	return(0);
}
