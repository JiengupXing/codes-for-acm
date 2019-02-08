#include <iostream>
#define maxn 100000000
using namespace std;
int pri[4010];
int num[maxn];
void prime()
{
    for(int i=2; i<maxn; i++)
    {
        if(num[i] == 0)
            pri[++pri[0]] = i;
        for(int j=1; (j<=pri[0])&&pri[j]<maxn/i; j++)
        {
            num[pri[j]*i] = 1;
            if(i%pri[j] == 0)
                break;
        }
    }
}
int main()
{
    prime();
    for(int i=1; i<=2000; i++)
    {
        cout<<pri[i]*pri[4000-i]<<endl;
    }
    return 0;
}
