#include <iostream>
#include <vector>
#include <set>
#define MAX 100000
using namespace std;
vector <int> g[MAX];
bool vis[MAX];
int parent[MAX], pre[MAX], low[MAX];
int cnt, n, m;

void dfs(int cur, int prev)
{
    pre[cur] = low[cur] = cnt;
    cnt++;
    vis[cur] = true;
    for(int i=0; i<g[cur].size(); i++)
    {
        int next = g[cur][i];
        if(!vis[next])
        {
            parent[next] = cur;
            dfs(next, cur);
            low[cur] = min(low[cur], low[next]);
        }
        else if(next != prev)
        {
            low[cur] = min(low[cur], pre[next]);
        }
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin>>n>>m;
    for(int i=1; i<=m; i++)
    {
        int s, t;
        cin>>s>>t;
        g[s].push_back(t);
        g[t].push_back(s);
    }
    dfs(0, -1);
    set <int> ap;
    int np = 0;
    for(int i=1; i<n; i++)//node number from 0
    {
        int p = parent[i];
        if(p == 0)
            np++;//if node ROOT's child node >1,root is a cut-vertex AKA gedian
        else if(pre[p] <= low[i])
            ap.insert(p);
        if(np >= 2)
            ap.insert(0);
        for(auto i:ap)
        {
            cout<<i;
        }
    }
}
