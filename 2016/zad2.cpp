
//zad2 insert to rst 
#define maxb = 10 

struct node
{
    int key;
    int counter;
    node * left ,*right;
} * root;

node ** search(int v, int &h)
{
    return nullptr;
}

struct maxCounter
{
    int hcount[100];
    int hM;
    int maxCount[100];
    node * max;

}*maxC;

void insertRST(int v)
{

    int h;
    node ** p = search(v,h);

    if( *p)
    {
        (*p)->counter++;
        // p istnieje
        if(h == maxC->hM)
        {
            //sprawdzamy czy p nie czesszte niz max
            if((*p)->counter > maxC->maxCount[h])
            {
                maxC->maxCount[h] = (*p)->counter;
                maxC->max = *p;
            }
            
        }
    }
    else //nie isitnieene
    {
        *p = new node{v,1,nullptr,nullptr};
        h++;
        maxC->hcount[h]++;

        //jezeli przeroslo
        if(maxC->hcount[h] > maxC->hcount[maxC->hM])
        {
            maxC->hM = h;

        }

    }

}