
int* Merge(int s1,int s2)
{
    return nullptr;
}

int A[100];
void MergeSort(int** sArr,int n,int A[])
{
    for(int i = n; i>1; i = i/2)
    {
        for(int j =0; j<i; j+=2)
        {
            int* temp = Merge(j,j+1);
            sArr[j] = nullptr;
            sArr[j+1] = nullptr;
            sArr[j/2] = temp;
        }
    }
    A = sArr[0];
}

