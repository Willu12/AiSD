

int A[200];
int n;

//zalozmy ze wstawiamy element jako A[n]

void Insert(int v)
{
    A[0] = 9999999;
    A[n] = v;

    while(v > A[(n+1)/3])
    {
        A[n] = A[(n+1)/3];

        n = (n+1)/3;

    }
    A[n] = v;
}

//usuwanie z kopca majacego trzy dzieci

void DelMax(int v)
{
    A[1] = A[n];
    //downHeap
    int i = 1;


    //while(A[1] > A[3*i -1] || A[])
}
