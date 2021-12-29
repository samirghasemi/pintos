#define UNVISITED -1
bool *visited;
int *ids, low, sccs;
int *stack;
node *stack;
int id;
int loop_index = 0;

void dfs(int at, list *loops, bool hasloop, node **adjacencyList)
{
    low[at] = id++;
    ids[at] = low[at];
    stack.push(at);
    visited[at] = true;
    for (int i = 0; i < sizeof(adjacencyList[at] / sizeof(adjacencyList[at][0])); i++)
    {
        if (ids[i] == UNVISITED)
        {
            dfs(i, loops, &hasloop, , adjacencyList);
        }
        if (visited[i])
        {
            low[at] = min(low[at], low[i]);
        }
    }
    if (ids[at] == low[at])
    {
        if(stack->size == 1){
            int n = stack.pop(); 
            visited[n] = false ; 
            return ; 
        }
        while (0 < stack->size)
        {
            int n = stack.pop();
            hasloop = true;
            visited[n] = false;
            if (adjacencyList[at][n].type == thread)
            {
                loops.push(adjacencyList[at][n].id);
            }
            if (n == at)
            {
                loop_index++;
                break;
            }
        }
    }
    return;
}

void tarjan(Graph *graph)
{
    int loop_index = 0;
    bool hasLoop = graph->hasloop;
    int **loops = graph->loops;
    node **adjList = graph->adjacencyList;
    visited = (int *)mallaloc(length);
    low = (int *)mallaloc(length);
    sccs = (int *)mallaloc(length);
    ids = (int *)mallaloc(length);
    *visited = {false};
    *ids = {UNVISITED};
    id = 0;
    for (int i = 0; i < length; i++)
    {
        if (ids[i] == UNVISITED)
        {
            dfs(i, loops, hasLoop, adjList);
        }
    }
}