#include <iostream>
#include <cstring>
using namespace std;
int n, cnt = 0;
int r[105];
bool c[105], m[105], sub[105];//m表示主对角线，sub表示副对角线
void print()
{
    cnt++;
    if(cnt<=3)
    {
        for(int i=1; i<=n; i++)
        {
            cout<<r[i]<<" ";
        }
        cout<<endl;
    }
}
void queen(int x)
{
    if(x>n)
    {
        print();
        return;
    }
    else
    {
        for(int i=1; i<=n; i++)
        {
            if(!c[i]&&!sub[i+x]&&!m[x-i+n])//主对角线上元素i-j的绝对值相等，副对角线上元素i+j相等
            {
                r[x] = i;
                c[i] = true;
                /*深度优先搜索（dfs）核心思想，标记访问-搜下一个-回溯*/
                sub[i+x] = true;
                m[x-i+n] = true;
                queen(x+1);
                c[i] = false;
                sub[i+x] = false;
                m[x-i+n] = false;
            }
        }

    }
}
int main()
{
    memset(c, false, sizeof(c));
    memset(m, false, sizeof(m));
    memset(sub, false, sizeof(sub));
    cin>>n;
    queen(1);
    cout<<cnt<<endl;
    return 0;
}