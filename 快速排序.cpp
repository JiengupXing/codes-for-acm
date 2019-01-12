//快速排序
//原地排序，不需要占用额外内存
//统计意义上o(nlog2n)/最坏情况o(n^2)
//随机基准数的方法可以使时间复杂度降低
#include <iostream>
#define MAX 100010
using namespace std;
//分割
//数组至整体有序，并返回分割点的下标
//o(n)
int Partition(int A[], int l, int r)//其中l和r均为数组下标
{
    int x = A[r];
    int i = l-1;
    int temp;
    for(int j=l; j<r; j++)
    {
        if(A[j] <= x)
        {
            i++;
            temp = A[j];
            A[j] = A[i];
            A[i] = temp;
        }
    }
    temp = x;
    A[r] = A[i+1];
    A[i+1] = x;
    return i+1;
}
void quicksort(int A[], int l, int r)
{
    int q;
    if(l<r)
    {
        q = Partition(A, l, r);
        quicksort(A, l, q-1);
        quicksort(A, q+1, r);
    }
}
int main()
{
    int n;
    int A[MAX];
    cin>>n;
    for(int i=0; i<n; i++)
    {
        cin>>A[i];
    }
    quicksort(A, 0, n-1);
    for(int i=0; i<n; i++)
    {
        if(!i)
            cout<<A[i];
        else
            cout<<" "<<A[i];
    }
    cout<<endl;
    return 0;
}
