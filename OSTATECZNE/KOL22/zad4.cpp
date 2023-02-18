struct node
{
    node* next;
    int val;
}*head;

void InsertionSort(node *& head)
{
    node* headS = nullptr;
    
    while(head)
    {
        //1. odlacz element
        node *p = head;
        head = head->next;
        p->next = nullptr;

        //2. znajdz dla niego miejsce na liscie headS
        node * qq = nullptr;
        node * q = headS;
        while(q && q->val < p->val) // < - anty , <= - stabilny
        {
            qq =q;
            q = q->next;
        }
        //3. przylacz go zatem ostatni znaklezionu
        // nie ma headS
        if(!qq)
        {
            p->next = headS;
            headS = p;
        }
        else
        {
            p->next = q;
            qq->next = p;
        }
    }
    head = headS;
}

void selectionSort(node *& head)
{
    node * headS = nullptr;
    while(head)
    {
        //1. znajdz najwiekszy element w liscie head
        node* ppMax = nullptr;
        node* pMax = head;
        node* p;
        while(p->next)
        {
            if(p->next->val >= pMax->val) // >= stab, > antystab
            {
                pMax = p->next;
                ppMax = p;
            }
        }
        // co i jak
        //2. odlacz element pMax z listy head
        if(pMax == head)
        {
            head = head->next;
        }
        else  ppMax->next = pMax->next;

        //3. dolacz do listy head na poczatek
        pMax->next = headS;
        headS = pMax;
    }
    head = headS;
}