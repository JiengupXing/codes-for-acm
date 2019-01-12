#include <stdio.h>
#include <string.h>
#include <string.h>

int dp[10][3];//dp[i][j]，i代表数字的位数，j代表状况
//dp[i][0],表示不存在不吉利数字
//dp[i][1],表示不存在不吉利数字，且最高位为2
//dp[i][2],表示存在不吉利数字
void Init()
{
    memset(dp,0,sizeof(dp));
    int i;
    dp[0][0] = 1;
    for(i = 1; i<=6; i++)//数字最长为6
    {
        dp[i][0] = dp[i-1][0]*9-dp[i-1][1];//最高位加上不含4的9个数字的状况，但因为会放6，所以要减去前一种开头为2的情况
        dp[i][1] = dp[i-1][0];//开头只放了2
        dp[i][2] = dp[i-1][2]*10+dp[i-1][0]+dp[i-1][1];//已经含有的前面放什么数都可以，或者是放一个4，或者是在2前面放6
    }
}

int solve(int n)
{
    int i,len = 0,tem = n,ans,flag,a[10];
    while(n)//将每一位拆分放入数组
    {
        a[++len] = n%10;
        n/=10;
    }
    a[len+1] = ans = 0;
    flag = 0;
    for(i=len; i>=1; i--)
    {
        ans+=dp[i-1][2]*a[i];
        if(flag)//如果已经是不吉利了，任意处理
            ans+=dp[i-1][0]*a[i];
        if(!flag && a[i]>4)//首位大于4，可以有放4的情况
            ans+=dp[i-1][0];
        if(!flag && a[i+1]==6 && a[i]>2)//后一位为6，此位大于2
            ans+=dp[i][1];
        if(!flag && a[i]>6)//此位大于6，可能的62状况
            ans+=dp[i-1][1];
        if(a[i]==4 || (a[i+1]==6&&a[i]==2))//标记为不吉利
            flag = 1;
    }
    return tem-ans;
}

int main()
{
    int l,r;
    Init();
    while(~scanf("%d%d",&l,&r),l+r)
    {
        printf("%d\n",solve(r+1)-solve(l));
        //因为solve函数中并没有考虑n是不是不幸数的情况，所以r+1只算了1~r，而l只算了1~l-1,这两者相减才是正确答案
    }

    return 0;
}
