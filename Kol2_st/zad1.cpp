#include <iostream>




class node
{
public:
  node* next;
  int v;

  node (node *n, int vals)
  {
    next = n;
    v = vals;
  }
};

node* head = nullptr;

void Add(int val)
{
    node *p = new node(head,val);
    head = p;
}

void PrintList()
{
    node *p = head;

    std::cout<<"[ ";
    while(p)
    {
        std::cout<<p->v<<" ";
        p = p->next;
    }
    std::cout<<"]\n";
}

node* SearchKeyPrev(int k )
{
    node* p = head;
    node* pp = nullptr;

    while(p && p->v!=k)
    {
        p = p->next;
        pp = pp->next;
    }
    if(!p) return nullptr;
    return pp;


}

node* SearchKeyMF(int k)
{
    //szukanie elementy
    node* pp = SearchKeyPrev(k);

    if(pp == nullptr) return nullptr;

    node* p = pp->next;
    pp->next = p->next;
    p->next = head;
    head = p;
    return p;

}


int main()
{
    //tworzenie przykladowej listy
    Add(5);
    Add(4);
    Add(12);
    Add(7);
    Add(33);
    Add(3);
    Add(12);
    PrintList();

    SearchKeyMF(33);
    PrintList();
    return 0;
}