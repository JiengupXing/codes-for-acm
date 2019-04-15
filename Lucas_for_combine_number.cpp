//#include <bits/stdc++.h>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <vector>
#include <map>
#include <queue>
#include <string>
#include <algorithm>
#define inf 0x3f3f3f3f
#define dbg cout << "!!!" << endl
//#define Local
using namespace std;
typedef long long ll;
const static int N = 5e6+5;

int p;

int inv[N], f[N], finv[N];

void init()
{
    inv[1] = 1;
    for(int i=2; i<p; i++)
    {
        inv[i] = (p-p/i) * 1ll * inv[p%i] % p;
    }
    f[0] = finv[0] = 1;
    for(int i=1; i<p; i++)
    {
        f[i] = f[i-1] * 1ll * i%p;
        finv[i] = finv[i-1] * 1ll *inv[i] % p;
    }
}

int comb(int n, int m)
{
    if(m < 0 || m > n)
        return 0;
    return f[n] * 1ll * finv[n-m]%p * finv[m] % p;
}

ll lucas(ll n, ll m, int p)
{
    return m?lucas(n/p, m/p, p) * comb(n%p, m%p) % p : 1;
}

int main()
{
#ifdef Local
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    ll s, k;
    cin>>k>>s>>p;
    init();
    if(s < k)
    {
        cout<<"0"<<endl;
        return 0;
    }
    cout<<lucas(s+k, 2*k, p)<<endl;
    return 0;
}