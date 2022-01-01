#include "graph.h"
#include "Stack.h"
#include "find_cycle.h"
#include "process"
#include "synch"
#include "list.h"
#include "syscall.h"
#include "stdio.h"
#include "stdlib.h"

#define get_length(arr) (sizeof((arr)) / sizeof(arr[0]))
struct Graph *graph;

enum Type resource_type = resource;
enum Type thread_type = thread;

static struct thread *choose_victim(list* cycle)
{   
    int average = 0;
    srand(time(0));
    int length = get_length(cycle);
    for (int i = 0; i < length; i++)
    {
        average += thread_get_by_id(cycle[i])->victimed_count;
    }
    int *low_victims = (int *)malloc(length * sizeof(int));
    int *high_victims = = (int *)malloc(length * size(int));
    int hight_count = 0;
    int low_count = 0;
    for (int i = 0; i < length; i++)
    {
        if (thread_get_by_id(cycle[i])->victimed_count > average)
        {
            high_victims[hight_count++] = cycle[i];
        }
        else
        {
            low_victims[low_count++] = cycle[i];
        }
    }
    struct thread *victim ; 
    int rand_num = rand()% 9 ;
    if(rand_num > 2 || get_length(high_victims) == 0){
        int rand_victim = rand() % low_count ;
        victim = thread_get_by_id(low_victims[rand_victim]);
    } else{
        int rand_victim = rand() % hight_count ; 
        victim = thread_get_by_id(high_victims[rand_victim]);
    }
    free(low_victims);
    free(high_victims);
    return victim;
}
static void recover(list* cycles)
{
    for(int i = 0 ; i < get_length(cycles) ; i++ )
    {
        struct thread *victim = choose_victim(cycles[i]);
        victim->victimed_count = victim->victimed_count++;
        while (!list_empty(&victim->locks))
        {
            struct lock *lock = list_pop_front(&victim->locks);
            lock_release(lock, victim);
        }
        process_exit(victim);
    }
}
static bool detect_deadlock()
{
    tarjan(&graph); //detect loops 
    return graph->hasCycle;
}

static void deadlock_detection_recovery()
{
    bool deadlock = detect_deadlock();
    if (deadlock)
    {
        recover(graph->loops);
    }
}

static void init_deadlock_detection(){
    graph = create_graph()
}
static void request_resources(int tid , int lock_id){
    add_edge(graph , tid , lock_id , resource_type)
}
static void receives_resources(int tid , int lock_id){
    delete_edge(graph, tid ,lock_id);
    add_edge(graph , tid , lock_id , thread_type)
}
static void frees_resource(int tid , int lock_id){
    delete_edge(graph, tid ,lock_id);
}


