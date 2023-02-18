int bit(int v, int bit);

int A[];

void RadicSort(int r, int l , int b)
{
    int j = r;
    int i = l;

    while(i < j)
    {
        while(bit(A[i],b) == 0 && i < j) i++;
        while(bit(A[i],b) == 1 && i<j) j--;

        int temp = A[i];
        A[i] = A[j];
        A[j] = temp;
    }
    // sprawdzenie na koniec j = 1 czy j = 0
    if(bit(A[j],b) == 0) j++;

    RadicSort(l,j-1,b-1);
    RadicSort(j,r,b-1);
}

