#include <stdio.h>
#include <string.h>

char a[100000];
char b[100000];
//数组开的不够大也会WA

void re(char a[])
{
    int flag = 0, len;
    len = strlen(a);
    for(int i=0; i<len; i++)
    {
        if(a[i] == '.')
        {
            flag = 1;
            break;
        }
    }
    if(flag)
    {
        for(int i=len-1; i>=0; i--)
        {
            if(a[i] == '0')
                a[i] = '\0';//去后导0
            else
                break;
            len--;
        }
        if(a[len-1] == '.')
            a[len-1] = '\0';//注意不要出现有小数点后面没有数字的情况
    }
}

int main()
{
    while(scanf("%s%s",a ,b) != EOF)
    {
        re(a);
        re(b);
        if(!strcmp(a, b))
        {
            printf("YES\n");
        }
        else
        {
            printf("NO\n");
        }
    }
    return 0;
}
