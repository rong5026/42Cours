#include <unistd.h>

void param(int n)
{
    if(n >= 10)
        param(n/10);
    char c = (n %10) + '0';
    write(1, &c, 1);
}
int main(int ac , char **av)
{
    (void)av;
    param(ac - 1);
    write(1, "\n", 1);
    return (0);
}