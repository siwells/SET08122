#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node * link;
};

void prepend(struct node **, int);
void append(struct node **, int);
int count(struct node *);
void delete(struct node **, int);
void display(struct node *);
void insert_after(struct node *, int, int);

int main(void)
{
    struct node *list;
    list = NULL;
    
    printf("No of elements in linked list = %d\n", count(list) );

    append(&list, 14);
    append(&list, 30);
    append(&list, 25);
    append(&list, 42);
    append(&list, 17);
    printf("No of elements in linked list = %d\n", count(list) );
    display(list);

    prepend(&list, 999);
    prepend(&list, 888);
    prepend(&list, 777);
    printf("No of elements in linked list = %d\n", count(list) );
    display(list);

    insert_after(list, 1, 0);
    insert_after(list, 2, 1);
    insert_after(list, 5, 99);
    printf("No of elements in linked list = %d\n", count(list) );
    display(list);

    insert_after(list, 99, 10);
    printf("No of elements in linked list = %d\n", count(list) );
    display(list);

    delete(&list, 99);
    delete(&list, 1);
    printf("No of elements in linked list = %d\n", count(list) );
    display(list);

    delete(&list, 10);
    printf("No of elements in linked list = %d\n", count(list) );
    display(list);

    return 0;
}

void prepend(struct node ** list, int num)
{
    struct node *temp;
    temp = (struct node *) malloc(sizeof(struct node));
    temp -> data = num;
    temp -> link = *list;
    *list = temp;
}

void append(struct node **list, int num)
{
    struct node *temp, *r;
    if(*list == NULL)
    {
        temp = (struct node *) malloc (sizeof(struct node));
        temp -> data = num;
        temp -> link = NULL;
        *list = temp;
    }
    else
    {
        temp = *list;
        while(temp -> link != NULL)
            temp = temp -> link;

        r = (struct node *) malloc(sizeof(struct node));
        r -> data = num;
        r -> link = NULL;
        temp -> link = r;
    }
}

int count(struct node * list)
{
    int count = 0;
    while(list != NULL)
    {
        list = list -> link;
        count++;
    }
    return count;
}

void delete(struct node ** list, int num)
{
    struct node *old, *temp;
    temp = *list;

    while(temp != NULL)
    {
        if(temp -> data == num)
        {
            if (temp == *list)
            {
                *list = temp -> link;
            }
            else
                old -> link = temp -> link;
                free(temp);
                return;
        }
        else
        {
            old = temp;
            temp = temp -> link;
        }
    }
    printf("Element %d not found in the supplied list\n", num);
}

void display(struct node * list)
{
    while(list != NULL)
    {
        printf("%d ", list -> data);
        list = list -> link;
    }
    printf("\n");
}

void insert_after(struct node * list, int location, int num)
{
    struct node *temp, *r;
    int i;
    temp = list;
    for(i=0; i<location; i++)
    {
        temp = temp -> link;
        if(temp == NULL)
        {
            printf("Length of list is %d but supplied location is %d\n", i, location);
            return;
        }
    }
    r = (struct node *) malloc (sizeof(struct node));
    r -> data = num;
    r -> link = temp -> link;
    temp -> link = r;
}

