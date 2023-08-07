#include <unistd.h>

void epur_str(char *str)
{
    int i = 0;
    int flag = 0;
    while(str[i] && ((str[i]>= 9 && str[i] <= 13)|| str[i] == 32))
        i++;
    while(str[i])
    {
        if(str[i] == ' ' || str[i] == '\t')
            flag = 1;
        
        else if(!(str[i] == ' ' || str[i] == '\t'))
        {
            if(flag == 1)
                write(1, " ", 1);
            flag = 0;
            write(1, &str[i], 1);
        }
        i++;
    }
}

int main(int ac, char **av)
{

	if (ac == 2)
        epur_str(av[1]);
	write(1, "\n", 1);
	return (0);
}
