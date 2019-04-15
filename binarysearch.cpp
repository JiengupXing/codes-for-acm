#include <iostream>
using namespace std;
int n;

inline bool check(int x);
//找到最后一个满足check的元素,找不到返回0
int bis(){
  int l=0,r=n+1,mid;//这样赋值可以满足找不到返回0的情况
  while(l<r){
    mid=l+r+1>>1;//这里mid的取值不同对应找到不同位置的满足条件的元素
    if(check(mid)) l=mid;
    else r=mid-1;
  }
  return r;
}

//找到第一个满足check的元素,找不到返回0

int bis(){
    int l=0,r=n+1,mid;
    while(l<r){
        mid=l+r>>1;
        if(check(mid)) r=mid;
        else l=mid+1;
    }
    return l;
}
