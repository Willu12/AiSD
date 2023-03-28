struct node
{
    node *next, *prev, *child;
    int v;
    int h;
}*root;

//by znalezc najminiejszt element w drzewie dwumianowym nalezy przejzec wszystkie jego elementy

//zlozonoscia bedzie 2^h 

node * min = root;

void CheckAll(node * root)
{
    if(!root) return;

    if(root->v < min->v)
    {
        min = root;
    }
    node* p = root->child;
    while(p)
    {
        CheckAll(p);
        p = p->next;
    }
    return;
}

void CheckAll2(node * root)
{
    if(!root) return;
    if(root->v < min->v)
    {
        min = root; 
    }
    CheckAll2(root->next);
    CheckAll2(root->child);
}
