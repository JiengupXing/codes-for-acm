#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;
int tree[1200100];
void pushup(int leaf)
{
    tree[leaf] = (tree[leaf*2]+tree[leaf*2+1]);
}

void build(int left, int right, int leaf)
{
    if(left == right)
    {
        scanf("%d", &tree[leaf]);
        return;
    }
    else
    {
        int m = (left+right)/2;
        build(left, m, leaf*2);
        build(m+1, right, leaf*2+1);
        pushup(leaf);
    }
}

int Query(int LEFT, int RIGHT, int left, int right, int leaf)
{
    if(LEFT<=left&&RIGHT>=right)
    {
        return tree[leaf];
    }
    else
    {
        int ans = 0;
        int m = (left+right)/2;
        if(m>=LEFT)
            ans += Query(LEFT, RIGHT, left, m, leaf*2);
        if(m<RIGHT)
            ans += Query(LEFT, RIGHT, m+1, right, leaf*2+1);
        return ans;
    }
}

void update(int num, int b, int left, int right, int leaf)
{
    if(left == right)
    {
        tree[leaf] += b;
    }
    else
    {
        int m = (right+left)/2;
        if(num<=m)
            update(num, b, left, m, leaf*2);
        else
            update(num, b, m+1, right, leaf*2+1);
        pushup(leaf);
    }
}

int main()
{
    int T;
    int cnt = 0;
    scanf("%d", &T);
    while(T)
    {
        memset(tree, 0, sizeof(tree));
        int N;
        int a, b;
        scanf("%d", &N);
        build(1, N, 1);
        /*for(int i=0;i<30;i++)
        printf("%d ",tree[i]);*/
        printf("Case %d:\n", ++cnt);
        char c[100];
        while(~scanf("%s", c))
            {
                if(c[0] == 'E')
                    break;
                scanf("%d%d", &a, &b);
                if(c[0] == 'Q')
                    printf("%d\n",Query(a, b, 1, N, 1));
                if(c[0] == 'A')
                {
                    //cout<<a<<b<<endl;
                    update(a, b, 1, N, 1);
                }
                if(c[0] == 'S')
                {
                    b = -b;
                    //cout<<a<<b<<endl;
                    update(a, b, 1, N, 1);
                }
                /*for(int i=0;i<30;i++)
                    printf("%d ",tree[i]);*/
            }
        T--;
    }
    return 0;
}
