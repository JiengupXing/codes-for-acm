#include <iostream>
#include <string.h>
using namespace std;
const static int N = 500005;
int nxt[N];
char a[N], b[N];
void kmp()//get pre[N],just like b[N] kmp itself
{
    int len = strlen(b);
    for(int i=1; i<len; i++)
    {
        int j = i;
        while(j > 0)
        {
            j = nxt[j];
            if(b[i] == b[j])
            {
                nxt[i+1] = j+1;
                break;
            }
        }
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin>>a;
    int cnt0 = 0, cnt1 = 0;
    for(int i=0; i<strlen(a); i++)
    {
        if(a[i] == '0')
            cnt0++;
        else
            cnt1++;
    }
    cin>>b;
    kmp();
    int n = strlen(b);
    /*for(int i=0; i<=n; i++)
    {
        cout<<nxt[i]<<endl;
    }*/
    for(int j=0; cnt0&&cnt1; j++)
    {
        if(b[j] == '0')
        {
            cout<<"0";
            cnt0--;
        }
        else
        {
            cout<<"1";
            cnt1--;
        }
        if(j == n-1)
            j = nxt[j+1]-1;
    }
    while(cnt0--)
        cout<<"0";
    while(cnt1--)
        cout<<"1";
    return 0;
}
