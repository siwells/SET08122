#include <stdio.h>

int isBigEndian()
{
    int x = 1;
    return(*(char *)&x != 1);
}

int main()
{
    printf("This is a %s endian machine\n", isBigEndian() ? "big" : "little");
    printf("char: %lu\n", sizeof(char));
    printf("short: %lu\n", sizeof(short));
    printf("int: %lu\n", sizeof(int));
    printf("long: %lu\n", sizeof(long));
    printf("long long: %lu\n", sizeof(long long));
    printf("float: %lu\n", sizeof(float));
    printf("double: %lu\n", sizeof(double));
    printf("long double: %lu\n", sizeof(long double));
}
