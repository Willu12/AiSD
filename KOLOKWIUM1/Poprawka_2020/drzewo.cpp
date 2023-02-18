
struct state
{
    state* next[3];
}*root;

struct path
{
    path * next;
    state* s;
};

struct List
{
    List* next;
    path *p;
};
List *head;
List *tail;

bool isSucces(state s)
{
    return true;
};

void findPaths(state* root)
{

}