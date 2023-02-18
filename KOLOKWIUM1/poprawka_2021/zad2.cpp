#include <iostream>

struct node
{
    node * left, *right;
    int key;
    int npl = 0; //dodanie np;
} *root;

//trzeba ustawic npl w drzewiue

node * max = root;

void setNPL(node * root)
{
    if(!root)  return;
    if(!root->left || !root->right) root->npl = 0; return; 

    root->npl = std::min(root->left->npl,root->right->npl) + 1;
}

void SearchWholeTree(node * root)
{
    if(!root) return;
    if(root->npl > max->npl)
    {
        max = root;
    }
    SearchWholeTree(root->left);
    SearchWholeTree(root->right);
}

// druga rzecz
// kopiec skoslny do kopca lewstronnego
// rekurencyjnie sprawdzac co i jak i zamienaic

void StoL(node * root)
{
    if(!root) return;

    if(!(root->left))   root->npl = 0;
    else
    {
        StoL(root->left);
    }

    if(!(root->right)) root->npl = 0;
    else
    {
        StoL(root->right);
    }

    //poprawa drzewa
    if(root->right && (! (root->left) || (root->right->npl > root->left->npl)))
    {
        node * temp = root->right;
        root->right = root->left;
        root->left = temp;
    }

    if(root->right)
    {
        root->npl = root->right->npl +1;    
    }
}



// konwersja kopca skosnego -> lewostronnego

void Convert(node * p)
{
    if(!p) return;
    
    //jezeli nie ma lewego poddrzewa
    if(!(p->left)) p->npl = 0;
    else    Convert(p->left);

    if(!(p->right)) p->npl = 0;
    else Convert(p->right);

    //ewentualna zaminaa
    if(p->right && (!(p->left) || (p->left->npl < p->right->npl)))
    {
        node * temp = p->right;
        p->right = p->left;
        p->left = temp;
    }

    if(root->right)
    {
        root->npl = root->right->npl + 1;
    }

    //na koniec uaktulanienie



}