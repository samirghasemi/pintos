#define N 10000

typedef enum{
    thread , resource
} Type;

struct Node{
    int id;
    Type type;
    struct Node* next;
}

struct list
{
  int data;
  struct list *next;
};

void push(struct list** head_ref, int new_data);

struct Graph{
    struct Node* adjacency_lists[N];
    bool hasLoop;
    struct list* loops;
}

struct Graph* createGraph();
void add_edge(struct Graph* graph, int tid , int lock_id, enum Type type);
void delete_edge(struct Graph* graph, int tid , int lock_id);
