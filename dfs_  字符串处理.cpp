#include <iostream>
#include <string>
using namespace std;
string s[25];
int used[25];
int maxlen = 0;
int n;
bool check(string a, string b, int k)//根据不同接口长度判断是否能够拼接
{
    int lena = a.size();
    for(int i=0; i<k; i++)
    {
        if(a[lena-k+i] != b[i])
            return false;
    }
    return true;
}
void add(string &a, string b, int k)
{
    int lenb = b.size();
    for(int i=k; i<lenb; i++)
    {
        a = a+b[i];
    }
}
void dfs(string now)
{
    int len = now.size();
    maxlen = max(maxlen, len);
    for(int i=1; i<=n; i++)
    {
        if(used[i]>=2)
            continue;
        int cur = s[i].size();
        for(int j=1; j<=cur; j++)//枚举接口长度
        {
            if(check(now, s[i], j))
            {
                string temp;//创建一个副本进行拼接，否则不能回溯，回溯后的now会改变，dfs中尤其需要注意这一点（有回溯过程）
                temp = now;
                add(temp, s[i], j);
                if(temp == now)
                    continue;
                used[i]++;
                dfs(temp);
                used[i]--;
            }
        }
    }
}
int main()
{
    string dra;
    cin>>n;
    for(int i=1; i<=n; i++)
    {
        cin>>s[i];
    }
    cin>>dra;
    dfs(dra);
    cout<<maxlen;
    return 0;
}
