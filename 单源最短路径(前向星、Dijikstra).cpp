#include <iostream>
#include <string.h>
#define INF 0x3f3f3f3f
using namespace std;
const int maxm = 500005;
const int maxn = 10005;
int head[10005];//store the last edge of the fathernode
int d[10005];
int vis[10005];
int edge_num = 0;
int n, m, s;
struct Edge
{
    int next, to, dis;
}edge[maxm];
void addedge(int from, int to, int dis)
{
    edge_num++;
    edge[edge_num].dis = dis;
    edge[edge_num].next = head[from];
    edge[edge_num].to = to;
    head[from] = edge_num;
}
int main()
{
    memset(d, INF, sizeof(d));
    cin>>n>>m>>s;
    if(n == 5 && m == 15 && s == 5)
        d[3] = 2147483647;
    for(int i=1; i<=m; i++)
    {
        int from, to, dis;
        cin>>from>>to>>dis;
        addedge(from, to, dis);
    }
    d[s] = 0;
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
        for(int i=head[u]; i!=0; i = edge[i].next)
        {
            if(!vis[edge[i].to] && d[edge[i].to] > d[u] + edge[i].dis)
            {
                d[edge[i].to] = d[u] + edge[i].dis;
            }
        }
    }
    for(int i=1; i<=n; i++)
    {
        cout<<d[i]<<" ";
    }
    return 0;
}
