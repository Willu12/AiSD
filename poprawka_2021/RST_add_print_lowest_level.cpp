/*
Dane jest drzewo RST, w którego węzłach znajduje się klucz 8-bitowy oraz licznik (counter).

- wstawianie liczby 8-bitowej (uaktualniania licznika, jeśli element już istnieje) do tego drzewa
- wypisywania par (key,counter) elementów znajdujących się na ostatnim istniejącym
poziomie drzewa
*/

#include <iostream>


#define maxb 10


class node
{
    public:
    node* right;
    node* left;
    int key;
    int counter;

    node (node *r,node* l, int vals)
    {
        right = r;
        left = l;
        key = vals;
        counter = 0;
    }
};



class lowList
{
    public:
    
    lowList * next;
    node * n; 
    int h ;

    lowList(lowList* nextt, node* node,int heig)
    {
        next = nextt;
        n = node;
        h = heig;
    }

};

bool bit(int v , int k)
{
    return true;
}

lowList *head = nullptr;
void Pushfront(node * n,int h)
{
    lowList *p = new lowList(head,n,h);
    if(!head)
    {
        head = p;
    }
}

node * root = nullptr;
void insertRST(int k)
{
    if(!root)
    {
        root = new node(nullptr,nullptr,k);
        Pushfront(root,1);
    }

    //szukanie w drzewie RST
    int b = maxb;
    node ** p = &root;

    while(*p && (*p)->key != k)
    {
        if(bit(k,b--) == 1)
        {
            p = &( (*p) ->right);
        }
        else
        {
            p = & ( (*p) -> left);
        }
    }

    // jezeli juz istenie
    if(*p)
    {
        (*p)->counter++;
    }
    else //nie istenie
    {
        *p = new node(nullptr,nullptr,k);
        //sprawdzenie czy dlugosc inna
        if(maxb - b == head->h)
        {
            Pushfront(*p,head->h);
        }
        else if(maxb -b > head->h)
        {
            head = nullptr;
            head = new lowList(nullptr,*p,maxb - b); 
        }
    }
}

// wypisywanie countoer
void PrintAll(lowList* head)
{
    lowList* p = head;

    while(p)
    {
        std::cout<<p->n->counter<<" " << p->n->key<< "\n";
        p = p->next;
    }
}
