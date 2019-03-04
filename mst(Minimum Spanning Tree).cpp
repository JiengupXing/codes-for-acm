#include <iostream>
#include <string>
#include <vector>
#include <string.h>
#define INF 0x3f3f3f3f
using namespace std;
int g[5005][5005];
int d[5005];
int vis[5005];
int p[5005];
int n, m, cnt = 0;
int mst()
{
    memset(p, -1, sizeof(p));
    memset(d, INF, sizeof(d));
    d[1] = 0;
    p[1] = 0;
    while(1)
    {
        int u = -1;
        int minn = INF;
        for(int i=1; i<=n; i++)
        {
            if(d[i] < minn && !vis[i])
            {
                u = i;
                minn = d[i];
            }
        }
        if(u == -1)
            break;
        vis[u] = 1;
        cnt++;
        for(int v=1; v<=n; v++)
        {
            if(!vis[v] && g[u][v] != INF)
                if(d[v] > g[u][v])
                {
                    d[v] = g[u][v];
                    p[v] = g[u][v];
                }
        }
    }
    int sum = 0;
    for(int i=1; i<=n; i++)
    {
        sum += p[i];
    }
    return sum;
}
int main()
{
    memset(g, INF, sizeof(g));
    cin>>n>>m;
    for(int i=1; i<=m; i++)
    {
        int x, y, z;
        cin>>x>>y>>z;
        g[x][y] = min(g[x][y], z);
        g[y][x] = min(g[y][x], z);
    }
    int ans = mst();
    if(cnt == n)
        cout<<ans<<endl;
    else
        cout<<"orz"<<endl;
    return 0;
}
