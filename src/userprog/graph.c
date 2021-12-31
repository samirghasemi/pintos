#define N 10000

void push(struct list** head_ref, int new_data)
{
    struct list* new_list = (struct list*) malloc(sizeof(struct list));
    new_list->data  = new_data;
    new_list->next = (*head_ref);
    (*head_ref)    = new_list;
}

struct Graph* createGraph()
{
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    for (int i = 0; i < N; i++) {
        graph->adjacency_lists[i] = (struct Node*)malloc(sizeof(struct Node));
    }
    return graph;
}

void add_edge(struct Graph* graph, int tid , int lock_id, enum Type type)
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->id = lock_id;
    newNode->type = type;
    newNode->next = graph->adjacency_lists[tid];
    graph->adjacency_lists[tid] = newNode;
}

void delete_edge(struct Graph* graph, int tid , int lock_id)
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    graph->adjacency_lists[tid] = newNode;
}
