#define max 100

struct node
{
    int des;
    node* next[10];

} *start; node* end;

struct path
{
    int len;
    path * next;
    path * prev;
    node * n;
} *head;
path * tail;

struct pathList
{
    path * p;
    pathList * next;
} *lHead;


//dodaj na koniec path node
void AddtoPath(node * nod)
{
    if(!head)
    {
        head = tail = new path{1,nullptr,nullptr,nod};
    }
    path* p = new path{tail->len++,nullptr,tail,nod};
    tail->next = p;
    tail = p;
}
void PopBackPath()
{
    tail = tail->prev;
    tail->next = nullptr;
}


void addPathtoList()
{
    path* headS, *tailS;
    path * p = head;

    tailS = headS = new path{head->len,nullptr,nullptr,head->n};
    while(p->next)
    {
        p = p->next;
        path * q = new path{tailS->len,nullptr,tailS,p->n};
        tailS->next =q;
        tailS = q;
    }
    if(!lHead)
    {
        lHead = new pathList{head,nullptr};
        return;
    }
    pathList * pL = new pathList{head,lHead};
    lHead = pL;
}



void findPath(node * state)
{
    if(tail->len > max) return;
    if(state->des == end->des)
    {   
        addPathtoList();
        return;
    }

    for(int i =0; i<10; i++)
    {
        AddtoPath(state->next[i]);
        findPath(state->next[i]);
        PopBackPath();
    }
}
