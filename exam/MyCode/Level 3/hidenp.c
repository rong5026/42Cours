#include <unistd.h>



void hidenp(char *str, char *str1)
{
    int i = 0;
    int j = 0;
    while(str1[i])
    {
        if(str1[i] == str[j])
        {
            j++;
        }
        i++;
    }
    if(str[j] == '\0')
        write(1, "1",1);
    else
        write(1, "0", 1);
}

int main(int ac, char **av)
{
    if (ac == 3)
        hidenp(av[1],av[2]);
	write(1, "\n", 1);
	return (0);
}
