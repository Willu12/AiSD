
struct node
{
    int key;
    node* prev, *next, *child;
}root;

node * max;

node* FindSecondMax(node * root)
{
    node* smax = max->child;

    node* c = max->child;
    // sprawdzamy czy na tym poziomie nie ma wiekszej wartosci
    while(c->prev != max->child)
    {
        c = c->prev;
        if(c->key > smax->key)
        {
            smax = c;
        }
    }

    //teraz musimy sprawdzic czy na poziomie roota nie ma innego wieszkeg
    node* p = root;
    while(p->prev != root)
    {
        p = p->prev;
        if(p->key > smax->key)
        {
            smax = p;
        }
    }
    return p;

    // musimy porownac wszystkie elemty na poziomie roota ktoruych jest n - liczba drzew
    // oraz wszystkie elementy bezposrednio na poziomie max->child ktorych moze byc bardzo duzooo :)
}


node * FindSecondMin(node * root)
{
    
}