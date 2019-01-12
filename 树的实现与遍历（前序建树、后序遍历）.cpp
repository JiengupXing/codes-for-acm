#include <iostream>
#include <cmath>
using namespace std;
char tree[1050];
void build(int left, int right)
{
    if(right>left)
    {
        int mid = (left+right)/2;
        build(left, mid);
        build(mid+1, right);
    }
    int flag1 = 1, flag2 = 1;
    for(int i=0; i<=right-left; i++)
    {
        if(tree[left+i] == '1')
            flag1 = 0;
        else if(tree[left+i] == '0')
            flag2 = 0;
    }
    if(flag1)
        cout<<"B";
    else if(flag2)
        cout<<"I";
    else
        cout<<"F";
}

int main()
{
    int n;
    cin>>n>>tree;
    build(0, pow(2, n)-1);
    return 0;
}
