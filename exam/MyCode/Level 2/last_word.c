#include <unistd.h>

void last_word(char *str)
{
    int size = 0;
    while(str[size])
        size++;
    
    int i = size - 1;
    while(i >=0 && ((str[i] >=9 && str[i]<=13) || str[i] ==32) )
        i--;
    while(i >=0)
    {
        if((str[i] >= 9 && str[i] <=13) || str[i] == 32)
            break;
        i--;
    }
    i++;
    while(str[i]>= 33 && str[i] <=127)
    {
        write(1, &str[i],1);
        i++;
    }
}

int main(int ac, char **av)
{
	if(ac == 2)
		last_word(av[1]);
	write(1, "\n", 1);
	return 0;
}
