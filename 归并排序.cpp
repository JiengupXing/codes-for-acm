//MERGESORT
//stable/o(nlog2n)
#include <iostream>
#define MAX 100010
#define INFTY 1500000000
using namespace std;
int L[MAX/2+2];
int R[MAX/2+2];
void Merge(int A[], int n, int left, int mid, int right)
{
    int n1 = mid - left;
    int n2 = right - mid;
    for(int i=0; i<n1; i++)
    {
        L[i] = A[left+i];
    }
    for(int i=0; i<n2; i++)
    {
        R[i] = A[mid+i];
    }
    L[n1] = INFTY;
    R[n2] = INFTY;
    int i=0, j=0;
    for(int k=left; k<right; k++)
    {
        if(L[i]>R[j])
        {
            A[k] = R[j];
            j++;
        }
        else
        {
            A[k] = L[i];
            i++;
        }
    }
    return;
}
void mergeSort(int A[], int n, int left, int right)
{
    if(left+1<right)// 只剩一个数的时候直接返回，否则一直递归分治
    {
        int mid = (left+right)/2;//就算是奇数也没关系，右边的数组本来就有一个不需合并
        mergeSort(A, n, left, mid);
        mergeSort(A, n, mid, right);
        Merge(A, n, left, mid, right);
    }
    return;
}
int main()
{
    int A[MAX];
    int n;
    cin>>n;
    for(int i=0; i<n; i++)
    {
        cin>>A[i];
    }
    mergeSort(A, n, 0, n);
    int flag = 1;
    for(int i=0; i<n; i++)
    {
        if(flag)
        {
            cout<<A[i];
            flag = 0;
        }
        else
        cout<<" "<<A[i];
    }
    cout<<endl;
    return 0;
}