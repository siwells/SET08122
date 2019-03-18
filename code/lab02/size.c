#include <stdio.h>

int main()
{
    int integerVariable;
    char charVariable;
    size_t size;

    size = sizeof(integerVariable);

    printf("Size of Integer Variable is %zu bytes\n", size);

    printf("Size of char Variable is %zu bytes\n", sizeof(charVariable));

    return 0;
}
