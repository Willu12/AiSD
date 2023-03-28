#define maxb 10


struct node
{
    node* right, *left;
    int key;
}*root;

int bit(int v , int k)
{
    return 1;
}



// szukanie w drzewie rest
node ** searchRST(int k,int &b)
{
    int b = maxb;

    node ** p = &root;

    while(*p && (*p)->key != k)
    {
        if(bit(k,b--) == 1)
        {
            p = &((*p)->right);
        }
        else
        {
            p = &((*p)->left);
        }
    }
    return p;
}

//dodawanie do drzewa RST
void insertRST(int v)
{   
    int h;
    node**p = searchRST(v,h);
    if(*p) return;

    *p = new node{nullptr,nullptr,v};
    if(!root)   root = *p;
}

//Usuwanie z drzewa RST

node* deleteRST(int v)
{
    int h;
    node**p = searchRST(v,h);
    if(*p = nullptr) return nullptr; //jakby gowno
    //jezeli p  jest lsciem
    if( !(*p)->left && !(*p)->right)
    {
        node *q = *p;
        *p = nullptr;
        return q;
    }
    //gdy nie jest lisciem
    //szuakmy dowolny lisc w  drzeiwie
    node ** q = p;
    while((*q)->right || (*q)->left)
    {
        if((*q)->left) q = & ((*q)->left);
        else    q = & ((*q)->right);
    }
    //mam wskaznik na liscia
    (*q)->right = (*p)->right;
    (*q)->left = (*q)->left;
    *p = *q;
    *q = nullptr;
}


//drzewa TRIE

//wyszukiwanie w drzewie TRIE
//dzewo TRIE ma elementy tylko w lisciach - szukamy liscia

node** searchTRIE(int v)
{
    int b = maxb;

    node**p = &root;
    while( (*p) && ((*p)->right ||(*p)->left))
    {
        if(bit(v,b--) == 1)
        {
            p = & ( (*p) ->right);
        }
        else
        {
            p = & ( (*p) ->left);
        }
    }
    return ( (*p) && (*p)->key == v) ? p : nullptr; 
}



// dzrzewa PATRICIA
struct nodeP
{
    nodeP* right, *left;
    int key;
    int nrbit;
}*rootP;

nodeP * searchPATRICIA(int v)
{
    // na 2 nody
    nodeP * p = rootP;
    nodeP * pp = nullptr;

    do
    {
        pp = p;
        if(bit(v,p->nrbit) == 1 )
        {
            p = p->right;
        }
        else p = p->left;
        
    } while (p && p->nrbit != pp->nrbit);
    return p;
}
