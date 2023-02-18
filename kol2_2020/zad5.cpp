class node
{
public:
  node* next;
  int v;

  node (node *n, int vals)
  {
    next = n;
    v = vals;
  }
};

void QuickSort(node *& head, node*& tail)
{
    int v = head->v;

    //tworzymy 3 sety
    node* headM = nullptr;
    node* headR = nullptr;
    node* headW = nullptr;
    node* tailM = nullptr;
    node* tailR = nullptr;
    node* tailW = nullptr;


    while(head)
    {
        //1. odlacz pierwszy elem
        node * p = head;
        head = head->next;
        p->next = nullptr;

        //2. dolacz do wybranego
        if(p->v < v)
        {
            if(!headM) tailM = p;
            p->next = headM;
            headM = p;
        }
        else if (p->v == v)
        {
            if(!headR) tailR = p;
            p->next = headR;
            headR = p;
        }
        else
        {
            if(!headW) tailW = p;
            p->next = headW;
            headW = p;
        }
    }

    // REKURENCJA   
    QuickSort(headM,tailM);
    QuickSort(headW,tailW);

    //3. polacz wyszstko ze soboa R na pewno istneije
    head = headR;
    tail = tailR;
    if(headM)
    {
        head = headM;
        tailM->next = headR;
    }
    tailR->next = headW;
    if(tailW)
    {
        tail = tailW;
    }
    //koniec :)
}