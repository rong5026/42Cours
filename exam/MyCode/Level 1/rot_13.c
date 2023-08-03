#include <unistd.h>

void print_rot_13(char *str)
{
    int i = 0;
    while(str[i])
    {
        char c = 0;
        if(str[i] >= 'a' && str[i] <='z')
        {
            c = (str[i] - 'a' + 13) % 26 + 'a';
        }
        else if(str[i] >= 'A' && str[i] <='Z')
        {
            c = (str[i] - 'A' + 13) % 26 + 'A';
        }
        else
        {
            c = str[i];
        }
        write(1, &c, 1);
        i++;
    }
}

int main(int ac, char **av)
{
    if(ac == 2)
        print_rot_13(av[1]);
    write(1, "\n", 1);
    return (0);
}