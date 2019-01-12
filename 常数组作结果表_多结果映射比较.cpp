#include <iostream>
using namespace std;
int pk[5][5] = {{0,0,1,1,0}, {1,0,0,1,0},{0,1,0,0,1},{0,0,1,0,1},{1,1,0,0,0}};
int a[210];
int b[210];
int main()
{
    int ansa = 0, ansb = 0;
    int N, NA, NB;
    cin>>N>>NA>>NB;
    for(int i=0; i<NA; i++)
    {
        cin>>a[i];
    }
    for(int i=0; i<NB; i++)
    {
        cin>>b[i];
    }
    for(int i=0; i<N; i++)
    {
        if(pk[a[i%NA]][b[i%NB]])
            ansa++;
        if(pk[b[i%NB]][a[i%NA]])
            ansb++;
    }
    cout<<ansa<<" "<<ansb<<endl;
    return 0;
}
