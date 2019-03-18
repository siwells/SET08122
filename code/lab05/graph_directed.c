#include <stdio.h>
#include <stdlib.h>

#define NUM_VERTICES 6

struct Graph
{
    struct Node* head[NUM_VERTICES];
};

struct Node
{
    int target;
    struct Node *next;
};

struct Edge
{
    int source;
    int target;
};

struct Graph* create_graph(struct Edge[], int);
void print_graph(struct Graph*);

int main(void)
{
    struct Edge edges[] =
	{
		{ 0, 1 }, { 1, 2 }, { 2, 0 }, { 2, 1 },
		{ 3, 2 }, { 4, 5 }, { 5, 4 }
	};

	int n = sizeof(edges)/sizeof(edges[0]);

	struct Graph *graph = create_graph(edges, n);

	print_graph(graph);
    return 0;
}

struct Graph* create_graph(struct Edge edges[], int num_edges)
{
    int i;
    struct Graph *graph = (struct Graph*) malloc(sizeof(struct Graph));

    for(i=0; i< NUM_VERTICES; i++)
    {
        graph -> head[i] = NULL;
    }

    for(i=0; i< num_edges; i++)
    {
        int source = edges[i].source;
        int target = edges[i].target;

        struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
        new_node -> target = target;
        new_node -> next = graph -> head[source];
        graph -> head[source] = new_node;
    }

    return graph;
}

void print_graph(struct Graph* graph)
{
	int i;
	for (i = 0; i < NUM_VERTICES; i++)
	{
		struct Node* ptr = graph->head[i];
		while (ptr != NULL)
		{
			printf("(%d -> %d)\t", i, ptr->target);
			ptr = ptr->next;
		}

		printf("\n");
	}
}

