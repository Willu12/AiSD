//usuwanie korzenia z  dzrzewa BST
// ktory posiada 2 niepuste nastepniki
//szukamy elemtnu do zmiany w prawym podrdszewie

//szuakmy lmin element w prawym poddrzewuie
struct node
{
    node *left,*right;
    int v;
} *root;

node* DelRoot(node *& root)
{
    if(!root) return nullptr;
    node *p = root->right;
    node *pp = root;
    while(p->left)
    {
        pp = p;
        p = p->left;
    }

    // gdy p ma prawe podrzewto przepianmy
    pp->left = p->right;
    p->right = root->right;
    p->left = root->left;

    root->right = root->left = nullptr;

    node * q = root;
    root = p;
    return q;


}
