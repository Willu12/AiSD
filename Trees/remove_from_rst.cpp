
//remove from root of RST tree
// you have to any leaf

#include <iostream>




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



node*  DeleteRST(node*& pmax,node*&pPrev)
{
    node *p = pmax;
    node* pp = pPrev;
    //szukamy liscia caly czas w lewo je`st chyba dobrz
    while(p->left || p->right)
    {
        pp = p;
        if(p->left)
        {
            p = p->left;
        }
        else
        {
            p = p->right;
        }
    }

    if(pp->right&& pp->right == p)  pp->right = nullptr;
    if(pp->left&& pp->left == p)  pp->left = nullptr;

    p->right = pmax->right;
    p->left = pmax->left;
    pp = pmax;
    pmax = p;
    return pmax;



    //szukamy lisica

}
