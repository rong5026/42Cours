#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

void pgcd(int a, int b)
{

    if(a <0 || b <0)
        return;
    int div = 1;

    int result;
    while(div <=a && div <=b)
    {
        if(a % div ==0 && b % div ==0)
            result = div;
        div++;
    }
    printf("%d", result);
    
}

int main(int ac, char **av)
{
    if(ac == 3)
    {
        int a = atoi(av[1]);
        int b = atoi(av[2]);
        pgcd(a,b);
    }

    write(1, "\n",1);
    return (0);
}