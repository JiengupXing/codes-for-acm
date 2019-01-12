#include <iostream>
#include <cstring>
using namespace std;
int v[30];
int w[30];
int rem[30][30010];
int dp(int num, int money)
{
    if(rem[num][money] != -1)
        return rem[num][money];
    if(num==0)
        return 0;
    else if(money<v[num])
        return rem[num][money] = dp(num-1, money);
    else
        return rem[num][money] = max(dp(num-1, money), dp(num-1, money-v[num])+v[num]*w[num]);
}
int main()
{
    memset(rem, -1, sizeof(rem));
    int maxm, n;
    cin>>maxm>>n;
    for(int i=1; i<=n; i++)
    {
        cin>>v[i]>>w[i];
    }
    dp(n, maxm);
    cout<<rem[n][maxm];
    return 0;
}
