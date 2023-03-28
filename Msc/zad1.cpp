struct node
{
    node* next;
    int val;
}*head;

node* SearchP(int v)
{
    node ** p = &head;
    while(*p && (*p)->val != v)
    {
        p = &((*p)->next);
    }
    if(!(*p)) return nullptr;

    node * q = *p;
    *p = (*p)->next;
    q->next = head->next;
    head = q;
    return q;
}

//ewentualne szukanie bez pdowojengo wskanizka
node * SearchMF(int v)
{
    node* p = head;
    node* pp = nullptr;
    while(p && p->val != v)
    {
        pp = p;
        p = p->next;
    }
    if(!p) return nullptr;
    pp->next = p->next;
    p->next = head;
    head = p;
}

// MF - polega na tym ze zawsze jak szukamy danego klucza po znalezieniu przestawiamy go
// na poczatek listy;
