#include <iostream>
#include <cstring>
using namespace std;
const static int maxn = 1000000+10;
const static int maxm = 10000+10;
int a[maxn];
int b[maxm];
int nxt[maxm];
int n, m;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        memset(a, 0, sizeof(a));
        memset(b, 0, sizeof(b));
        memset(nxt, 0, sizeof(nxt));
        cin>>n>>m;
        int ans = -1;
        for(int i=0; i<n; i++)
        {
            cin>>a[i];
        }
        for(int i=0; i<m; i++)
        {
            cin>>b[i];
        }
        for(int i=1; i<m; i++)
        {
            int j = i;
            while(j > 0)
            {
                j = nxt[j];
                if(b[j] == b[i])
                {
                    nxt[i+1] = j+1;
                    break;
                }
            }
        }
        for(int i = 0, j = 0; i < n; i++)
        {
            if(j < m && a[i] == b[j])
                j++;
            else
            {
                while(j > 0)
                {
                    j = nxt[j];
                    if(a[i] == b[j])
                    {
                        j++;
                        break;
                    }
                }
            }
            if(j == m)
            {
                ans = i-m+2;
                break;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
