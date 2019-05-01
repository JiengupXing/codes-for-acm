#include <iostream>
#include <cmath>
#include <cstdio>
#include <cstring>
using namespace std;
const static int maxn = 5e4+10;
int n, m;
int max_node[maxn][20];//二维的大小看log2n最大为多少就行
int min_node[maxn][20];
int a[maxn];
void rmq()
{
	int temp = (int)(log((double)n)/log(2.0));
	for(int i=1; i<=n; i++)
	{
		max_node[i][0] = min_node[i][0] = a[i];
	}
	for(int j=1; j<=temp; j++)
	{
		for(int i=1; i<=n; i++)
		{
			if(i + (1 << (j-1)) <= n)
			{
				max_node[i][j] = max(max_node[i][j-1], max_node[i+(1<<(j-1))][j-1]);
				min_node[i][j] = min(min_node[i][j-1], min_node[i+(1<<(j-1))][j-1]);
			}
		}
	}
}

int query(int l, int r)
{
	int k = (int)(log((double)(r - l + 1))/log(2.0));
	//printf("%d %d", max(max_node[l][k], max_node[r - (1 << k)+1][k]), min(min_node[l][k], min_node[r - (1 << k)+1][k]));
	return max(max_node[l][k], max_node[r - (1 << k)+1][k]) - min(min_node[l][k], min_node[r - (1 << k)+1][k]);
}

int main()
{
    while(scanf("%d %d", &n, &m) != EOF)
    {
        memset(max_node, 0, sizeof(max_node));
        memset(min_node, 0, sizeof(min_node));
        for(int i=1; i<=n; i++)
        {
            scanf("%d", &a[i]);
        }
        rmq();
        for(int i=1; i<=m; i++)
        {
            int l, r;
            scanf("%d %d", &l, &r);
            printf("%d\n", query(l, r));
        }
    }
    return 0;
}
