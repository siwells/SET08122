#include <time.h>
#include <stdio.h>

#define SIZE 1000

void code()
{
/*    for(long i=0; i<SIZE; i++)
    {
        printf(".");
    }    */

/*    for(long i=0; i<SIZE; i++)
    {
        for(long j=0; j<SIZE; j++)
        {
            printf(".");
        }
    }    
    printf("\n");*/

    for(long i=0; i<SIZE; i++)
    {
        for(long j=0; j<SIZE; j++)
        {
            printf(".");
        }
    }    
    printf("\n");
}

int main()
{
    clock_t t;
    printf("start: %d \n", (int) (t=clock()));

    code();

    printf("stop: %d \n", (int) (t=clock()-t));
    printf("Elapsed: %f seconds\n", (double) t / CLOCKS_PER_SEC);

    return 0;
}

