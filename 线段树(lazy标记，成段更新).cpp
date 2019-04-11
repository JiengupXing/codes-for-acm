#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const static int maxn = 100010;

int sum[maxn<<4];
int mark[maxn<<4];

void Pushdown(int m, int rt)
{
    if(mark[rt])
    {
        mark[rt<<1] = mark[rt];
        mark[rt<<1|1] = mark[rt];
        //int mid = (left + right)>>1;
        sum[rt<<1] = (m - (m>>1))*mark[rt<<1];
        sum[rt<<1|1] = (m>>1)*mark[rt<<1|1];
        mark[rt] = 0;
    }
}

void build(int left, int right, int rt)
{
    mark[rt] = 0;
    sum[rt] = right-left+1;
    if(left == right)
        return;
    int mid = (left+right)>>1;
    build(left, mid, rt<<1);
    build(mid+1, right, rt<<1|1);
}

void Update(int c, int _left, int _right, int left, int right, int rt)
{
    if(_left <= left && _right >= right)
    {
        mark[rt] = c;
        sum[rt] = (right-left+1)*mark[rt];
        return;
    }
    Pushdown(right-left+1, rt);
    int mid = (left+right)>>1;
    if(mid >= _left)
        Update(c, _left, _right, left, mid, rt<<1);
    if(mid < _right)
        Update(c, _left, _right, mid+1, right, rt<<1|1);
    sum[rt] = sum[rt<<1]+sum[rt<<1|1];
}

int main()
{
    int t;
    int CASE = 0;
    scanf("%d", &t);
    while(t--)
    {
        int n, m;
        scanf("%d", &n);
        scanf("%d", &m);
        build(1, n, 1);
        for(int i=1; i<=m; i++)
        {
            int a, b, c;
            scanf("%d %d %d", &a, &b, &c);
            Update(c, a, b, 1, n, 1);
        }
        printf("Case %d: The total value of the hook is %d.\n", ++CASE, sum[1]);
    }
    return 0;
}
