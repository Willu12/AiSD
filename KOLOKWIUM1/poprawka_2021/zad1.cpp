/*Porównaj programowanie zachłanne z dynamicznym. Zaproponuj (napisz funkcję)
zachłanny algorytm szukania ścieżki w dowolnym drzewie od korzenia do liścia o najmniejszej
sumie wartości elementów w węzłach. Funkcja ma utworzyć „globalną” listę wskazań na
kolejne elementy tej ścieżki (zaczynając od korzenia, a kończąc na liściu). Czy napisany
algorytm znajduje poprawnie taką ścieżkę? Uzasadnij.
Zaproponuj odpowiednie struktury danych. Nie jest znana maksymalna liczba poddrzew.
ISI: nie można używać wbudowanych/bibliotecznych tablic/list dynamicznych*/

struct node
{
    node *left,*right;
    int v;
} *root;

struct nodeList
{
    nodeList *next;
    node* n;
    nodeList(nodeList *ne, node* nn)
    {
        next = ne;
        n = n;
    }
} *head;
nodeList* tail;

void pushbackList(node * p)
{
    nodeList* L = new nodeList(nullptr,p);
    if(!head)
    {
        head = tail = L;
        return;
    }
    tail->next = L;
    tail = L;
}

void CreateGreedyList(node * root)
{
    if(!root) return;
    node *p = root;

    pushbackList(p); 

    while(p->left || p->right) //dopoki nie jest lisciem
    {
        if(p->left && p->right) //jezeli jest wybor
        {
            if(p->left->v < p->right->v)
            {
                p = p->left;
            }
            else    p = p->right;
        }
        else if(p->left)    p = p->left;
        else p = p->right;

        pushbackList(p);
    }
}

// ten algorytm nie znajdue poprawnie sciezki o najmniejszej sumie lementow