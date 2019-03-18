#include <stdio.h> 

typedef struct
{
    int id;
    char name [30]; 
} employee;

int main()
{
    employee e1 = {1, "Simon"};
    printf("ID: %d\nName: %s\n", e1.id, e1.name);
    printf("%zu %zu %zu \n", sizeof(e1.id), sizeof(e1.name), sizeof(e1)); return(0);
}
