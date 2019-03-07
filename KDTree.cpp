#include <iostream>
#include <algorithm>
#include <vector>
#define MAX 1000000
#define NIL -1
using namespace std;
struct node
{
    int p, l, r;
    int location;
}T[MAX];
struct point
{
    int x, y;
    int id;
    bool operator < (const point &a)
    {
        return id < a.id;
    }
}P[MAX];
bool compx(point &a, point &b)
{
    return a.x < b.x;
}
bool compy(point &a, point &b)
{
    return a.y < b.y;
}
int n;
int np;
int makeKDTree(int l, int r, int depth)
{
    if(l >= r)
        return NIL;
    int mid = (l+r)/2;
    int t = np++;
    if(depth % 2 == 0)
    {
        sort(P+l, P+r, compx);
    }
    else
    {
        sort(P+l, P+r, compy);
    }
    T[t].location = mid;
    T[t].l = makeKDTree(l, mid, depth+1);
    T[t].r = makeKDTree(mid+1, r, depth+1);
    return t;
}
void query(int v, int lx, int rx, int ly, int ry, int depth, vector<point> &ans)
{
    int x = P[T[v].location].x;
    int y = P[T[v].location].y;
    if(x>=lx && x<=rx && y>=ly && y<=ry)
    {
        ans.push_back(P[T[v].location]);
    }
    if(depth % 2 == 0)
    {
        if(T[v].l != NIL)
            if(x >= lx)
                query(T[v].l, lx, rx, ly, ry, depth+1, ans);
        if(T[v].r != NIL)
            if(x <= rx)
                query(T[v].r, lx, rx, ly, ry, depth+1, ans);
    }
    else
    {
        if(T[v].l != NIL)
            if(y >= ly)
                query(T[v].l, lx, rx, ly, ry, depth+1, ans);
        if(T[v].r != NIL)
            if(y <= ry)
                query(T[v].r, lx, rx, ly, ry, depth+1, ans);
    }
}
int main()
{
    ios::sync_with_stdio(false);
    int x, y;
    scanf("%d", &n);
    for(int i=0; i<n; i++)
    {
        scanf("%d %d", &x, &y);
        P[i].x = x;
        P[i].y = y;
        P[i].id = i;
        T[i].l = NIL;
        T[i].r = NIL;
        T[i].p = NIL;
    }
    np = 0;
    int root = makeKDTree(0, n, 0);
    int q;
    scanf("%d", &q);
    int lx, rx, ly, ry;
    vector<point> ans;
    for(int i=1; i<=q; i++)
    {
        scanf("%d %d %d %d", &lx, &rx, &ly, &ry);
        ans.clear();
        query(root, lx, rx, ly, ry, 0, ans);
        sort(ans.begin(), ans.end());
        for(int j=0; j<ans.size(); j++)
        {
            printf("%d %d\n", ans[j].x, ans[j].y);
        }
        printf("\n");
    }
    return 0;
}
