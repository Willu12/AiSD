int sArr[64];

void Merge(int a, int b,int * Sarr)
{
    // scal dwa zwroc 1
    // wstwaia do sArr na adres a scalony lancuch
    // Sarr[b] = -1;
    //zwraca indeks poczatku tej tablicty
} 

void mergeSort(int A[], int SArr[],int n)
{
    for(int j = 1 ; j<64; j*=2)
    {
        for(int i =0; i<n; i+=2*j)
        {
            Merge(i,i+j,sArr);
        }
        n = n/2;
    }
}

