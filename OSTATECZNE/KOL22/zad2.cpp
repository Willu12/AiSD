struct node
{
    node* next[2];
    int key;
};

node* deleteRST(node * pMin, node *& pPrev)
{
    //sprawdzaenie czy p min jest lisciem
    if(!pMin->next[0] && !pMin->next[1])
    {
        if(pPrev->next[0] && pPrev->next[0]->key == pMin->key)
        {
            pPrev->next[0] = nullptr;
        }
        else if(pPrev->next[1] && pPrev->next[1]->key == pMin->key)
        {
            pPrev->next[1] = nullptr;
        }
        return pMin;
    }

    // nie jest lisciem wiec szukamy liscia z jego podrdzewa
    node * q = pMin;
    node * qq = pPrev;
    int right = 0;
    while(q->next[0] || q->next[1])
    {
        qq = q;
        //gdy mozemy to w lewo
        if(q->next[0])
        {
            q = q->next[0];
            right = 0;
        }
        else
        {
            q = q->next[1];
            right = 1;
        }
    }
    // mamy lisicia
    if(pPrev->next[0] && pPrev->next[0]->key == pMin->key)
    {
        pPrev->next[0] = q;
    }
    else if(pPrev->next[1] && pPrev->next[1]->key == pMin->key)
    {
        pPrev->next[1] = q;
    }

    if(right)   qq->next[1] = nullptr;
    else    qq->next[0] = nullptr;

    return pMin;
}