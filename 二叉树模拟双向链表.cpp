/*蒟蒻的我不会链表

所以我只能用树做了

思路：

1.用树存点与点之间的前后关系

2.用中序遍历的方法输出

*/

#include<cstdio>
struct lol{int lc,rc,v;} d[101000];//v表示是否被删，lc是左儿子(相当于当前点的前面的第一个数)，rc是右儿子 (相当于当前点的后面的第一个数)
void dfs(int x)//用中序遍历的方法输出 
{
    if(x==-1)return;//-1代表没空，如果该点为空就不需要再往下找 
    dfs(d[x].lc);//搜左儿子 
    if(d[x].v==0)printf("%d ",x);//搜完左儿子（相当于输完前面的人的编号）输出自己的编号 
    dfs(d[x].rc);//搜右儿子 
}
int main()
{
    int n,m;scanf("%d",&n);
    d[1].v=0;d[1].lc=d[1].rc=-1;
    //-1表示空，初始化第一个点 
    for(int i=2;i<=n;i++)
    {
        int x,y;scanf("%d %d",&x,&y);
        d[i].lc=d[i].rc=-1;d[i].v=0;//先初始化i点 
        if(y==0)
        {
            if(d[x].lc!=0)//当d[x]有左儿子，把当前点的左儿子设为d[x]的左儿子，d[x]左儿子设为当前点
            {d[i].lc=d[x].lc;d[x].lc=i;} 
            //否则，把d[x]有左儿子设为当前点
            else d[x].lc=i;
        }
        else
        {
            if(d[x].rc!=0)//当d[x]有右儿子，把当前点的右儿子设为d[x]的右儿子，d[x]右儿子设为当前点
            {d[i].rc=d[x].rc;d[x].rc=i;} 
            //否则，把d[x]有右儿子设为当前点
            else d[x].rc=i;
        }
    }
    scanf("%d",&m);
    for(int i=1;i<=m;i++)
    {
        int x;scanf("%d",&x);d[x].v=1;//删除x点 
    }
    dfs(1);//利用中序遍历输出 
}