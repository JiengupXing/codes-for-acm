#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
#include<cmath>
#include<cstdlib>
#include<queue>
#include<stack>
#include<map>
#include<vector>
#include<functional>
using namespace std;
int heap[123],size,d,n,ans;
void put(int d)
{
	heap[size++]=d;
	push_heap(heap,heap+size,greater<int>());
}
int get()
{
	pop_heap(heap,heap+size,greater<int>());
	return heap[--size];
}
priority_queue<int, vector<int>,greater<int> >q;
int main()
{
	freopen("fruit2.in","r",stdin);
	freopen("fruit2.out","w",stdout);
	scanf("%d",&n);
	for(int i=0;i<n;i++) 
	{
		scanf("%d",&d);
		q.push(d);
	}
	for(int i=1;i<n;i++)
	{
		int a=q.top(); q.pop();
		int b=q.top(); q.pop();
		q.push(a+b);
		ans+=a+b;
	}
	printf("%d",ans);
	return 0;