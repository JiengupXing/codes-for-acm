#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int dp[11][11];
void init()
{
    int i, j, k;//i为当前位，j枚举当前位上的数字，k枚举上一位上的数字
    for(i=0; i<=9; i++)
        dp[1][i] = 1;
    dp[1][4] = 0;
    for(i=2; i<=7; i++)
    {
        for(j=0; j<=9; j++)
        {
            if(j==4)
                continue;
            for(k=0; k<=9; k++)
            {
                if(k!=4&&!(j==6&&k==2))
                    dp[i][j] += dp[i-1][k];
            }
        }
    }
}
int solve(int n)
{
    int i, j, k;
    int a[10];
    int lenth = 0, ans = 0;
    while(n)
    {
        a[++lenth] = n%10;
        n = n/10;
    }
    a[lenth+1] = 0;//这里是表明最高一位的前一位不是6，也就是最高一位可以枚举2
    for(i=lenth; i>0; i--)//因为预处理的时候是从位数下标为1开始的，后面用到的dp[i][j]里面的i也应该从1开始枚举，一直到lenth
    {
        for(j=0; j<a[i]; j++)//这里小于所给的数的当前位上的最大值，ans的值就已经把所有的可能情况都枚举完了，不用等于这个值
        {
            if(j==4 || (j==2&&a[i+1]==6))
                continue;
            ans += dp[i][j];
        }
        if(a[i]==4 || (a[i]==2&&a[i+1]==6))
            break;//这里为什么是break？
    }
    return ans;
}

int main()
{
    init();
    int m, n;
    while(cin>>m>>n, m+n)
    {
        cout<<solve(n+1) - solve(m)<<endl;
    }
    return 0;
}
