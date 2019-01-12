#include <stdio.h>
#define N 1000
int gbc(int a, int b);
int main()
{
    int n, ans, result;
    int number[N];
    while(scanf("%d",&n)!=EOF)
    {
        for(int i=0; i<n; i++)
        {
            scanf("%d",&number[i]);
        }
        if(number[0]>number[1])
        {
            ans = gbc(number[0],number[1]);
        }
        else
        {
            ans = gbc(number[1],number[0]);
        }
        result = (number[0]/ans*number[1]);
        for(int i=2; i<n; i++)
        {
            if(result>number[i])
                ans = gbc(result,number[i]);
            else
                ans = gbc(number[i],result);
            result = result/ans*number[i];
            //Highlight!!! the position is very inmportant!!!
            //这里用这种写法避免result*number[i]超出int的范围
        }
        printf("%d\n",result);
    }
    return 0;
}
int gbc(int a, int b)
{
    if(!b)
        return a;
    else
        return gbc(b,a%b);
}
