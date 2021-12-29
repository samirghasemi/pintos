#define detection_frequency 100
#define get_length(arr) (sizeof((arr)) / sizeof(arr[0]))
struct Graph *graph;

enum Type resource_type = resource;
enum Type thread_type = thread;

static struct thread *choose_victim(list* cycle);
static void recover(list* cycles);
static bool detect_deadlock();
static void deadlock_detection_recovery();
static void init_deadlock_detection();
static void request_resources(int tid , int lock_id);
static void receives_resources(int tid , int lock_id);
static void fress_resource(int tid , int lock_id);


