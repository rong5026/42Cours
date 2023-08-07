
#include <unistd.h>


void wdmatch(char *str, char *str1)
{
    int i = 0;
    int cnt = 0;
    while(str[cnt])
        cnt++;
    int j =0;
    while(str1[i])
    {
        if(str1[i] == str[j])
        {
            j++;
        }
        i++;
    }
    if(j == cnt)
    {
        i = 0;
        while(str[i])
            write(1, &str[i++],1);
    }
}

int main(int ac, char **av)
{
    if(ac == 3)
        wdmatch(av[1],av[2]);
    write(1, "\n",1);   
}