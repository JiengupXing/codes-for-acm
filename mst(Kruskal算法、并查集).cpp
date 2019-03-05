#include <iostream>
#include <algorithm>
using namespace std;
struct edge
{
    int u, v;
    int w;
}e[200005];
int fa[5005];
int n, m;
bool comp(edge a, edge b)
{
    return a.w<b.w;
}
int getfather(int x)
{
    while(x != fa[x])
        x = fa[x] = fa[fa[x]];
    return x;
}
int main()
{
    int ans = 0;
    cin>>n>>m;
    for(int i=0; i<m; i++)
    {
        cin>>e[i].u>>e[i].v>>e[i].w;
    }
    sort(e, e+m, comp);
    int cnt = n;
    for(int i=1; i<=n; i++)
        fa[i] = i;
    for(int i=0; i<m; i++)
    {
        int t1 = getfather(e[i].u);
        int t2 = getfather(e[i].v);
        if(t1 != t2)
        {
            fa[t1] = t2;
            ans += e[i].w;
            cnt--;
            if(cnt == 1)
                break;
        }
    }
    cout<<ans;
    return 0;
}
