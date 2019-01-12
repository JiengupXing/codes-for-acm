#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int dp[11][11];
int a[10];
void init()
{
    int i, j, k;//iΪ��ǰλ��jö�ٵ�ǰλ�ϵ����֣�kö����һλ�ϵ�����
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
    a[lenth+1] = 0;//�����Ǳ������һλ��ǰһλ����6��Ҳ�������һλ����ö��2
    for(i=lenth; i>0; i--)//��ΪԤ�����ʱ���Ǵ�λ���±�Ϊ1��ʼ�ģ������õ���dp[i][j]�����iҲӦ�ô�1��ʼö�٣�һֱ��lenth
    {
        for(j=0; j<a[i]; j++)//����С�����������ĵ�ǰλ�ϵ����ֵ��ans��ֵ���Ѿ������еĿ��������ö�����ˣ����õ������ֵ
        {
            if(j==4 || (j==2&&a[i+1]==6))
                continue;
            ans += dp[i][j];
        }
        if(a[i]==4 || (a[i]==2&&a[i+1]==6))
            continue;
    }
    return ans;
}

int main()
{
    init();
    int m, n;
    while(cin>>m>>n, m+n)
    {
        cout<<solve(n) - solve(m-1)<<endl;
    }
    return 0;
}
