struct node
{
    node * left, *right;
    int val;
    int bl;
} * root;


node* Delete(int v)
{
    //szuakmy jak w drzewie BST z pdowojny m**
    if(!root) return nullptr;
    node **p = &root;

    while(*p && (*p)->val != v)
    {
        p = (*p)->val < v ?  &((*p)->right) : &((*p)->left);
    }
    // jezeli nie ma
    if(*p == nullptr) return nullptr;

    if((*p)->right)
    {
        *p = (*p)->right;
    }
    else *p = (*p)->left;
}
