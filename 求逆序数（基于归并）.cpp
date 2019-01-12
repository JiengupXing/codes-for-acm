//求逆序数
//基于归并
//时间复杂度o(nlogn)
#include <iostream>
using namespace std;
const int MAX = 5e5+10;
int A[MAX], L[MAX/2], R[MAX/2];
long long Merge(int a[], int left, int mid, int right)
{
    int n1 = mid - left;
    int n2 = right - mid;
    long long ans = 0;
    for(int i=0; i<n1; i++)
    {
        L[i] = a[left+i];
    }
    for(int i=0; i<n2; i++)
    {
        R[i] = a[mid+i];
    }
    L[n1] = 1000000010;
    R[n2] = 1000000010;
    int i = 0, j = 0;
    for(int k=left; k<right; k++)
    {
        if(L[i] <= R[j])
        {
            a[k] = L[i];
            i++;
        }
        else
        {
            a[k] = R[j];
            j++;
            ans += n1-i;//合并时由此可得有多少个R里的元素到了L里元素的后面，即与该元素相关的逆序数
        }
    }
    return ans;
}
long long mergesort(int a[], int left, int right)
{
    long long  v1, v2, v3;
    if(left+1<right)
    {
        int mid = (right+left)/2;
        v1 = mergesort(a, left, mid);
        v2 = mergesort(a, mid, right);
        v3 = Merge(a, left, mid, right);
        return v1+v2+v3;//答案由子问题求得的逆序数加上合并时产生相关的逆序数之和得到
    }
    else
        return 0;
}
int main()
{
    int n;
    cin>>n;
    for(int i=0; i<n; i++)
    {
        cin>>A[i];
    }
    long long ans = mergesort(A, 0, n);
    cout<<ans;
    return 0;
}
