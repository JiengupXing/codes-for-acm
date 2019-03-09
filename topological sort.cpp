#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#include <list>
#include <string.h>
#define maxn 1<<5
using namespace std;
vector<int> g[maxn];
bool vis[maxn];
int indeg[maxn];
list<int> out;
int n, m;
void bfs(int x)
{
    vis[x] = true;
    queue<int> q;
    q.push(x);
    while(!q.empty())
    {
        int u = q.front();
        q.pop();
        out.push_back(u);
        for(int i=0; i<g[u].size(); i++)
        {
            int v = g[u][i];
            indeg[v]--;
            if(indeg[v] == 0 && !vis[v])
            {
                vis[v] = true;
                q.push(v);

            }
        }
    }
}
void tsort()
{
    for(int u=0; u<n; u++)
    {
        for(int i=0; i<g[u].size(); i++)
        {
            int v = g[u][i];
            indeg[v]++;
        }
    }
    for(int u=0; u<n; u++)
    {
        if(indeg[u]==0 && !vis[u])
            bfs(u);
    }
    list<int>::iterator iter;
    for(iter = out.begin(); iter != out.end(); iter++)
    {
        cout<<*iter<<endl;
    }
    return;
}
int main()
{
    ios::sync_with_stdio(false);
    cin>>n>>m;
    for(int i=1; i<=m; i++)
    {
        int from, to;
        cin>>from>>to;
        g[from].push_back(to);
    }
    tsort();
    return 0;
}
