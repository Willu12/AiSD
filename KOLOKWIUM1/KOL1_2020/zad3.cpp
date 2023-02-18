struct node
{
    node* next, *prev, *child;
    int v;
    int h;
}*root;


void FixTree(node *& root)
{
    //tworzymy tablice poddrzew roota
    node * subTrees[root->h];
    
    int h = root->h;
    node * p = root->child;
    root->child == nullptr;
    root->h = 0;
    while(p)
    {
        subTrees[p->h] = p;
        p = p->next;
    }

    //tworzymy nowe drzewo i dopoki nie zostalo usniete po kolei

    if(subTrees[0])
    {
        root->child = subTrees[0];
        root->h++;
    }
    //mamy tablice wksazan an poddrzewe z przypisanymi im rozmiarami
    int i =1;
    p = root->child;
    while(subTrees[i])
    {
        //chcemy dodac podrzdwo do roota
        root->child->prev->next = subTrees[i];
        subTrees[i]->prev = root->child->prev;
        subTrees[i]->next = nullptr;
        root->child->prev = subTrees[i];
        i++;
        root->h++;
    }
    // tak dodajemy kolejne podrzewa po kolei do poki nie bedzie dziury
    // po dziurze dodajemy poddrzewa do kolejki dwumianowej
    for(i; i<h; i++)
    {
        if(subTrees[i] != nullptr)
        {
            //dodajemy po kolei po prawo od roota
            root->prev->next = subTrees[i];
            subTrees[i]->prev = root->prev;
            subTrees[i]->next  = nullptr;
            root->prev = subTrees[i];
        }
    }
    
}