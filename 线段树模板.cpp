#define lson l,m,rt*2
#define rson m+1,r,rt*2+1

void pushup(int rt)
{
    		tree[rt]=tree[rt<<1]+tree[rt<<1|1];
}
int Query(int L,int R,int l,int r,int rt)
{
  	 if(L<=l&&r<=R)
    	{
        return tree[rt];
    }
    	else
    {
        		int m=(l+r)>>1;
       	 	int ans=0;
      	  	if(L<=m)
        		{
          	  	ans+=Query(L,R,lson);
      		}
        if(m<R)
        {
            ans+=Query(L,R,rson);
        }
        return ans;
    }
}
void build( int l ,int r , int rt )
{
 if( l == r )
 {
  scanf("%d",&tree[rt]);
  return ;
 }
 else
 {
  int m = (l+r)>>1 ;
  build(lson) ;
  build(rson) ;
  pushup(rt) ;
 }
}
void update(int p,int c,int l,int r,int rt)//
{
    //printf("%d %d %d %d %d\n",p,c,l,r,rt);
    if(l==r)
    {
        tree[rt]+=c;
    }
    else
    {
        int m=(l+r)>>1;
        if(p<=m) update(p,c,lson);
        else  update(p,c,rson);
        pushup(rt);
  //printf("sum[%d]:%d\n",rt,tree[rt]);
    }
}


--------------------- 
作者：mengxiang000000 
来源：CSDN 
原文：https://blog.csdn.net/mengxiang000000/article/details/50173775 
版权声明：本文为博主原创文章，转载请附上博文链接！