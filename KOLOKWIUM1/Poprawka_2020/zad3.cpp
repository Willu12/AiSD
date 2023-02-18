struct node
{
 int key;
 int mark;
 node *prev, *next, *child, *parent;
};
node *head;


bool ExtractFromParent(node* n)
{
    if(n->parent == nullptr) return false; //sprawdzenie czy rodzic istenieje

    node * par = n->parent;
    
    // wyrzucenie elementu n z dzieci p;
    node * c = par->child;
    // co jezeli c rowne p 
    if(c == n)
    {   
        node * p = c->next;
        p->prev = c->prev;
        c->next = nullptr;
        par->child = p;
        
       
    }

    while(c && c!=n)
    {
        c = c->next;
    }
    node * pp = c->prev;
    pp->next = c->next;
     if(c->next)
    {
        c->next->prev = c->prev;
    }
    c->prev = nullptr;
   

    c->parent = nullptr;
    par->mark++;
    return par->mark > 1 ? false : true; 
}