#include <unistd.h>


void   first_word(char *str)
{
    int i = 0;

    while(str[i] && str[i] == ' ')
    {
        i++;
    }
    while(str[i] && str[i] != ' ')
    {
        write(1, &str[i], 1);
        i++;
    }
}

int main(int ac, char **av)
{
    if(ac == 2)
        first_word(av[1]);
    write(1,"\n",1);
    return (0);
}