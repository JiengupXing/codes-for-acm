#include <iostream>
using namespace std;
int cnt = 0;
int n, k;
void dfs(int last, int sum, int now)
{
    if(now == k)
    {
        if(sum == n)
            cnt++;
        return;
    }
    for(int j=last; sum+j*(k-now)<=n; j++)//��֦-���������ǵ����ģ�����ö�ٱ�lastС��Ԫ�����������
        dfs(j, sum+j, now+1);
}
int main()
{
    cin>>n>>k;
    dfs(1, 0, 0);
    cout<<cnt<<endl;
    return 0;
}
