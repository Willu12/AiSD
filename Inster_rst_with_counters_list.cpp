#include <iostream>

struct node
{
    node *right, *left;
    int val;
    int counter;
    node(node * r,node *l , int v)
    {
        right =r;
        left = l;
        val = v;
        counter = 1;
    }
};
struct levelList
{

    node* n;
    levelList* next;   
};

levelList* tab[100];
int h_counter[100];
int max_h;

node ** search(int v, int &h)
{
    return nullptr;
}

void inserRST(int v)
{
    int h;
    node**p = search(v,h);

    // p juz jest w drzewie RST
    if(*p)
    {
        (*p)->counter++;
        return;
    }
    // nie ma p ttrzeba dodoac
    h++;
    tab[h]++;
    *p = new node(nullptr,nullptr,v);
    if(h_counter[max_h] < h)
    {
        max_h = h;
    }
}

void PrintMaxCounter()
{
    levelList* p = tab[max_h];
    levelList* maxL = p;

    if(!p) return;

    while(p)
    {
        if(p->n->counter > maxL->n->counter);
        maxL = p;
        p = p->next;
    }
    std::cout<<p->n->val<<"\n";
    
}
