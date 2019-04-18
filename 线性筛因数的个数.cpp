#include <iostream>
#include <time.h>

using namespace std;
const static int maxn = 1e6+5;
int prim[maxn], d[maxn], num[maxn];
bool mark[maxn];
int cnt;
void init()
{
    cnt = 0;
    d[1] = 1;
    for(int i=2; i<maxn; i++)
    {
        if(!mark[i])
        {
            prim[cnt++] = i;
            num[i] = 1;
            d[i] = 2;
        }
        for(int j=0; j<cnt&&i*prim[j]<maxn; j++)
        {
            mark[i*prim[j]] = 1;
            if(!(i%prim[j]))
            {
                num[i*prim[j]] = num[i]+1;
                d[i*prim[j]] = d[i]/(num[i]+1) * (num[i*prim[j]]+1);
                break;
            }
            d[i*prim[j]] = d[i] * d[prim[j]];
            num[i*prim[j]] = 1;
        }
    }
}

int main()
{
    clock_t start, _end;
    start = clock();
    init();
    _end = clock();
    cout<<(float)(_end-start)*1000/CLOCKS_PER_SEC<<"ms"<<endl;
    return 0;
}
