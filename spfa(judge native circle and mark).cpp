/*SPFA算法判断负环：
1. bfs 判断标准是若一个节点入队大于ｎ次，则说明存在负环
2. dfs 判断标准是一个点在多个路径上出现，则说明存在负环
*/
#include <iostream>
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
using namespace std;
//DFS judge native circle
void DFS_SPFA(int u){
    if(flag) return ;
    vis[u]=true;
    for(int i=head[u];i;i=edges[i].nxt){
        if(flag) return ;
        int v=edges[i].v;
        if(d[u]+edges[i].t<d[v]){
            d[v]=d[u]+edges[i].t;
            if(vis[v]){
                flag=true;
                return ;
            }else{
                DFS_SPFA(v);
            }
        }
    }
    vis[u]=false;
}

void bfs(int x)
{
    circle[x] = true;
    for(int i=0; i<g[x].size(); i++)
    {
        int v = g[x][i].second;
        if(!circle[v])
            bfs(v);
    }
}
//bfs judge native circle and mark all the relative node
void spfa_dfs(int start)
{
    bool inque[maxn];
    int inq_cnt[maxn];
    for(int i=1; i<=n; i++)
        d[i] = inf;
    memset(inque, false, sizeof(inque));
    memset(inq_cnt, 0, sizeof(inq_cnt));
    queue <int> q;
    q.push(start);
    inq_cnt[start]++;
    d[start] = 0;
    while(!q.empty())
    {
        int u = q.front();
        q.pop();
        inque[u] = false;
        for(int i=0; i<g[u].size(); i++)
        {
            int v = g[u][i].second;
            if(circle[v])
                continue;
            int cost = g[u][i].first;
            if(d[v] > d[u] + cost)
            {
                d[v] = d[u] + cost;
                if(!inque[v])
                {
                    q.push(v);
                    inque[v] = true;
                    inq_cnt[v]++;
                    if(inq_cnt[v] > n)
                        dfs(v);
                }
            }
        }
    }
}
