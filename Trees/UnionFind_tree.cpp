
int fathers[10];
int Find(int elNo)
{
    int i = elNo;
    while(fathers[i] > 0)
    {
        i = fathers[i];
    }

    //poprawa dzrewa
    int j = elNo;
    while(fathers[j] > 0)
    {
        int temp = fathers[j];
        fathers[j] = i;
        j = temp;
    }
    return fathers[i];
}
