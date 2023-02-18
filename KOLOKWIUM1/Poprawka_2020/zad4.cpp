//struktura bdzrzewa
#define m 512
#define inf 9999

struct node
{
    // z wartownikiem 
    int key[2*m + 1];

    node * next[2*m +1];

    int k;
} *root;


node* search(node * root, int v)
{
    if(!root) return nullptr;

    node * p = root;

    root->key[0] = -inf;
    int i = root->k;
    while(root->key[i] > v)
    {
        i--;
    }
    if(root->key[i] == v) return root;

    return search(root->next[i],v);

}

bool CheckBeforeDelete(int v)
{
    //1. szukamy elementu
    //2. patrzymy czy ilosc elementow k > m

    // szukamy strony na ktorej bybly ten elemnt

    node * p = search(root,v);

    if(p == nullptr) return false; // taka strona nie istenije

    if(p->k > m) return true;
    return false;
}