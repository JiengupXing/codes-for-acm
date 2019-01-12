#include <iostream>
using namespace std;
int cnt = 0;
int n, k;
void dfs(int last, int sum, int now)
{
    if(now == k)
    {
        if(sum == n)
            cnt++;
        return;
    }
    for(int j=last; sum+j*(k-now)<=n; j++)//剪枝-由于数列是递增的，所以枚举比last小的元素是无意义的
        dfs(j, sum+j, now+1);
}
int main()
{
    cin>>n>>k;
    dfs(1, 0, 0);
    cout<<cnt<<endl;
    return 0;
}
