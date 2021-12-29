typedef enum{
    thread , resource
} Type;

struct Node{
    int id;
    Type type;
    struct Node* next;
}

struct Graph{
    struct Node** adjacency_lists;
    bool hasLoop;
    struct list* loops;
}