
//drzewa czerwono czarne

struct node
{
    node *left, *right;
    int black;
    int val;
}*root;


node * find(int v)
{
    node * p = root;
    while(p && p->val != v)
    {
        p = p->val < v ? p->right : p->left;
    }
    return p;
}
