
char *ft_strrev(char *str)
{
    int size = 0;
    while(str[size])
        size++;
    
    int i = 0;
    while(i < size / 2)
    {
        char tmp = str[i];
        str[i] = str[size - 1 - i];
        str[size - 1 - i] = tmp;
        i++;
    }
    return (str);
}
