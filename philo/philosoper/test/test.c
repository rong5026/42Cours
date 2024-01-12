#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>

int main(void)
{
    pid_t childpid[5];
	int		i;

	i = -1;
	while (++i < 5)
	{
		childpid[i] = fork();
        if (childpid[i] > 0)
		{
			printf("parent pid is %d\nchild pid is %d\n", getpid(), childpid[i]);
			printf("parent is write now\t%d\n\n", i);
		}
		else if (childpid[i] == 0)
		{
			printf("child is write now\n\n");
			break ;
		}
		else
		{
			printf("Fork Error\n");
		}
	}
	return (1);
}