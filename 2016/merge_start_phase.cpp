#define max 100

int tab[max];

void MergeStartPhase(int* indexes,int& len)
{
    indexes[max];
    int last = tab[0];
    len = 1;
    indexes[0] = 0;
    for(int i =0; i<max; i++)
    {

        if(tab[i - 1] < tab[i])
        {
            len++;
            indexes[len - 1] = i;
        }
    }
}