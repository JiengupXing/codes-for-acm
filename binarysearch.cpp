#include <iostream>
using namespace std;
int n;

inline bool check(int x);
//找到最后一个满足check的元素
// mid=(l+r+1)>>1 不会取到 l。因此，若我们将初始的二分范围 [l,r] 扩大到 (l−1,r]，一旦二分无解，则最终返回的下标将会是 l−1。
int bis(){
  int l=0,r=n+1,mid;//这样赋值可以满足找不到返回0的情况
  while(l<r){
    mid=l+r+1>>1;//这里mid的取值不同对应找到不同位置的满足条件的元素
    if(check(mid)) l=mid;
    else r=mid-1;
  }
  return r;
}

//找到第一个满足check的元素
//mid=(l+r)>>1 不会取到 r。因此，若我们将初始的二分范围 [l,r] 扩大到 [l,r+1)，一旦二分无解，则最终返回的下标将会是 r+1。
int bis()
{
    int l=0,r=n+1,mid;
    while(l<r){
        mid=l+r>>1;
        if(check(mid)) r=mid;
        else l=mid+1;
    }
    return l;
}

//这种写法比较好记，返回-1表示没找到符合条件的点，否则跳出循环时的r为答案
int bis()
{
	int l = 0, r = 1e9;
	while(r-l > 1)
	{
		int mid = (r+l)>>1;
		if(check(mid))
			r = mid;
		else
			l = mid;
	}
	return r == 1e9 ? -1 : r;
}
