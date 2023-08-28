#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
using namespace std;

int main(){
    IOS;
    int x,y,m;cin>>x>>y>>m;
    int res = 0;
    for(int i=0;i*x<=m;i++)
        for(int j=0;j*y+i*x<=m;j++)
            res = max(res,j*y+i*x);
    cout<<res<<"\n";
    return 0;
}
