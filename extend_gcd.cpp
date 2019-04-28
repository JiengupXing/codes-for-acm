//返回 d=gcd(a,b); 和对应于等式 ax+by=d 中的 x,y
int ex_gcd(int a, int b, ll &x, ll&y)
{
    if (b == 0)
    {
        x = 1;
        y = 0;
        return a;
    }
    ll x1, y1;
    int gcd = ex_gcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - (a/b) * y1;
    return gcd;
}

//解不等式ax + by = c
//令d = extend_gcd(a, b, x, y) => x = x0, y = y0
//c%d==0时才存在整数解
//则一组解为(x0 * c/d, y0 * c/d)
//解系为((x0 * u*(b/d))*(a/d), (y0 * v*(a/d))*(b/d)) 其中 u*(b/d)*(a/d) + v*(a/d)*(b/d)=0
//x的最小解为xmin = (x0*(c/d))%(b/d) 可能得到负数,所以我们可以再加上一个(b/d)就强行得到正整数了
