class node
{
public:
  node* next;
  int val;

  node (node *n, int vals)
  {
    next = n;
    val = vals;
  }
};


node* insertionSortList(node* head) 
    {
        node * headS = nullptr;

        while(head)
        {
            //1. odlacz pierwysz element
            node* p = head;
            head = head->next;
            p->next = nullptr;
            //2. znajdz elem za ktory wstawidc
            node *q = headS;
            node *qq = nullptr;
            while(q && q->val <= p->val)
            {
                qq = q;
                q = q->next;
            }
            //3 . dodanie za qq
            if(qq == nullptr)
            {
                p->next = headS;
                headS = p;
            }
            else
            {
                p->next = qq->next;
                qq->next = p;
            }
        }
        return headS;
    }