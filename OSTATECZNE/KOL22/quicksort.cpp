
struct node
{
    node * next;
    int val;
} *head,*tail;

void QuickSortS(node*& head,node*& tail)
{
    int v = head->val;
    //1. tworzymy wymageane gowno
    node * headM = nullptr;
    node * tailM = nullptr;
    node * headR = nullptr;
    node * tailR = nullptr;
    node * headW = nullptr;
    node * tailW = nullptr;
    while(head)
    {
        //1. odlacz od heada
        node * p  = head;
        head = head->next;
        p->next = nullptr;
        //2. wybierz zbior do ktore ma trafic dany node
        if(p->val < v)
        {
            if(!headM)  p = headM = tailM;
            tailM->next = p;
            tailM = p;
        }
        else if(p->val == v)
        {
            if(!headR)  p = headR = tailR;
            tailR->next = p;
            tailR = p;
        }
        else if(p->val > v)
        {
            if(!headW)  p = headW = tailW;
            tailW->next = p;
            tailW = p;
        }
        // mamy podzielone teraz QUicksort na podziobrack
        QuickSortS(headW,tailW);
        QuickSortS(headM,tailM);
        head  = headR;
        tail = tailR;
        // polacz wszystko
        if(headM)
        {
            tailM->next = head;
            head = headM;
        }
        if(headW)
        {
            tail->next = headW;
            tail = tailW;
        }
    }
}