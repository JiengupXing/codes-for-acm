//树的遍历互求，递归实现
#include <iostream>
#include <string>
using namespace std;
string sin, spost;
void preview(int inl, int inr, int postl, int postr)
{
    cout<<spost[postr];
    int m = sin.find(spost[postr]);
    if(m>inl)
        preview(inl, m-1, postl, postl+m-inl-1);
    if(m<inr)
        preview(m+1, inr, postr+m-inr, postr-1);
}
int main()
{
    cin>>sin>>spost;
    preview(0, sin.size()-1, 0, sin.size()-1);
    return 0;
}
