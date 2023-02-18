int countArr[100];
int setArr[100];
int elemArr[100];


// O(1)
void Union(int set1,int set2, int setOut)
{
    int r1 = setArr[set1];
    int r2 = setArr[set2];

    if(countArr[set1] >= countArr[set2])
    {
        elemArr[r2] = r1;
        elemArr[r2] = -setOut;
        setArr[set2] = -1;
        setArr[set1] = -1;
        setArr[setOut] = r1;
    }
    else
    {
        elemArr[r1] = r2;
        elemArr[r1] = -setOut;
        setArr[set2] = -1;
        setArr[set1] = -1;
        setArr[setOut] = r2;
    }
    countArr[setOut] = countArr[set1] + countArr[set2];
    countArr[set1] = countArr[set2] = 0;
}

//szukanie z kompresja scziezki
int find(int el)
{
    int i = elemArr[el];
    while(i > 0)
    {
        i = elemArr[i];
    }

    //kompresja
    int root = i;
    int i = elemArr[el];
    while(i > 0)
    {
        int temp = elemArr[i];
        elemArr[i] = root;
        i = temp;
    }
    return -root;
    
}
//pesymistyzna O(n), zamortyzowana O(1)