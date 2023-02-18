struct node
{
    node* next;
    int v;
    node(node* n, int val)
    {
        next = n;
        v = val;
    };
}*head;


void ShiftToEnd(node *&head1,node*& head, node *&tail)
{
    head1->next = nullptr;
    if(!head)
    {
        head = tail = head1;
        return;
    }
    tail->next = head1;
    tail = head1;
}


void MergeTail(node * head1, node* tail1,node* head2, node* tail2, node* & head,node*& tail)
{
    while(head1 && head2)
    {
        if(head1->v <= head2->v)
        {
            ShiftToEnd(head1,head,tail);
        }
        else
        {
            ShiftToEnd(head2,head,tail);
        }
    }
    if(head1)
    {
        tail->next = head1;
        tail = tail1;
    }
    else if(head2)
    {
        tail->next = tail2;
        tail = tail2;
    }
}

node * popFront(node*& head)
{
    if(!head) return nullptr;

    node * p = head;
    head = head->next;
    p->next = nullptr;
}

node * Merge(node* head1, node * head2)
{
    node * head = nullptr;
    //dodanie do head
    if(head1->v <= head2->v)
    {
        head = popFront(head1);
    }
    else
    {
        head = popFront(head2);
    }

    node * tail = head;
    // petla while
    while(head1 && head2)
    {
        if(head1->v <= head2->v)
        {
            tail ->next = popFront(head1);
        }
        else
        {
            tail->next = popFront(head2);
        }
    }
    // jeden sie musial skomnczucsz
    if(head1)
    {
        tail->next = head1;
    }
    if(head2)
    {
        tail->next = head2;
    }
    return head;
}



node* PArr[100];

void NRMergeSort()
{
    node* pLast;
    int iLast = 0;
    //dodanie pierwszego elementu przed petla
    if(head)
    {
        node *p = head;
        head = head->next;
        p->next = nullptr;
        pLast = p;
    }
    // normalna petla
    while(head)
    {
        // odlacz pierwszy elemnt
        node *p = head;
        head = head->next;
        p->next = nullptr;

        if(pLast->v <= p->v)
        {
            pLast->next = p;
        }
        else
        {
            PArr[iLast++] = p;
        }
        p = pLast;
    }

    //sprawdzamy czy jest tylko jeden lanczuszek
    while(PArr[1] != nullptr)
    {
        int i =0;
        while(PArr[i+1] != nullptr)
        {
            PArr[i/2] = Merge(PArr[i],PArr[i+1]);
            PArr[i] = PArr[i+1] = nullptr;
            i*=2;
        }
    }    
}