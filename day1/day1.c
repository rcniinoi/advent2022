#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include "get_next_line.h"

int main(void)
{
	int		openfd = open("input", O_RDONLY );
	char	*buffer;
	int		cur = 0;
	int		max[3];
	int		i = 0;
	int		sum = 0;
	buffer = get_next_line(openfd);
	while (buffer)
	{
		cur += atoi(buffer);
		if (buffer && buffer[0] == '\n')
		{
			if (cur > max[2])
			{
				if (cur > max[1])
				{
					if (cur > max[0])
					{
						max[2] = max[1];
						max[1] = max[0];
						max[0] = cur;
					}
					else
					{
						max[2] = max[1];
						max[1] = cur;
					}
				}
				else
				{
					max[2] = cur;
				}
			}
			cur = 0;
		}
		buffer = get_next_line(openfd);
	}
	// while (intarray[++i])
	sum = max[0] + max[1] + max[2];
		printf("--%d-%d-%d---%d\n", max[0], max[1], max[2], sum);
	// printf("%d\n", openfd);
}
