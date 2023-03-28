class node
{
public:
  node* left;
  node* right;
  int v;

  node (node *r,node*l, int vals)
  {
    right = r;
    left = l;
    v = vals;
  }
};

void Splay(node *&, int v)
{}

node* tab[10];

void Split(node* tab[100], node** tab1, node** tab2,int v)
{
  for(int i =0; i<100; i++)
  {
    Splay(tab[i],v);
    tab2[i] = tab[i] -> right;
    tab1[i] = tab[1];
    tab1[i]->right = nullptr;
    // powinno byc git
   // dziwnw
  }
}

node** Concatenate(node* tab[100],node** tab1, node** tab2,int v)
{
  for(int i =0; i<100; i++)
  {
    Splay(tab1[i],tab2[i]->v);
    tab1[i]->right = tab2[i];
  }
  return tab1;
}
