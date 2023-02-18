struct state
{
    state* next[3];
} *root;

//sciezki statnow
struct node
{
    node* next, *prev;
    state* s;
};

node * head;
node* tail = head = new node{nullptr,nullptr,root};

// lista sciezek
struct list
{
    list* next;
    node* n;
} *listHead;

//funkcja dodajaca stan do na koniec sziekci
void pushbackstate(state* s, node *& tail)
{
    node * p = new node{nullptr,tail, s};
    tail->next = p;
    tail = p;
}
void popBack(node*& tail)
{
    tail = tail->prev;
    tail->next = nullptr;
}

void PathToList(node * head)
{
    list *L = new list{nullptr,head};
    if(!listHead)
    {
        listHead = L;
        return;
    }
    //gdy head juz jest
    L->next = listHead;
    listHead = L;
}

bool isSucces(state * n)
{
    return true;
}
void findPaths(state * s)
{
    if(!s) return;
    if(isSucces(s))
    {
        //dodanie do listy winkowej
        PathToList(head);
        return;
    }

    for(int i =0; i<3; i++)
    {
        pushbackstate(s->next[i],tail);
        findPaths(s->next[i]);
        popBack(tail);
    }
}

void PrintAllPaths()
{
    list * L = listHead;

    while(L)
    {
        node * p = L->n;
        while(p)
        {
            //print p->state
            p = p->next;
        }
        L = L->next;
    }

}