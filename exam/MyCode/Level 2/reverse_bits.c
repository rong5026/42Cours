unsigned char	reverse_bits(unsigned char octet)
{
    int     idex;
    unsigned char bit;

    idex = 7;
    while (idex >= 0)
    {
        bit = ((bit*2) + (octet % 2));
        octet/=2;
        idex--;
    }
    return (bit);
}

