#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
using namespace std;

void solve(){
    int n,m;cin>>n>>m;
    int x1,y1,x2,y2;cin>>x1>>y1>>x2>>y2;
    if((x1==1&&y1==1)||(x1==n&&y1==1)||(x1==1&&y1==m)||(x1==n&&y1==m)){
        if(abs(x1-x2)+abs(y1-y2)==1)cout<<1<<"\n";
        else cout<<2<<"\n";return;
    }
    if((x2==1&&y2==1)||(x2==n&&y2==1)||(x2==1&&y2==m)||(x2==n&&y2==m)){
        if(abs(x1-x2)+abs(y1-y2)==1)cout<<1<<"\n";
        else cout<<2<<"\n";return;
    }
    if(x1==1 || x1==n || y1 == 1 || y1 == m){
        if(abs(x1-x2)+abs(y1-y2)==1)cout<<2<<"\n";
        else cout<<3<<"\n";return;
    }
    if(x2==1 || x2==n || y2 == 1 || y2 == m){
        if(abs(x1-x2)+abs(y1-y2)==1)cout<<2<<"\n";
        else cout<<3<<"\n";return;
    }
    if(abs(x1-x2)+abs(y1-y2)==1)cout<<3<<"\n";
    else cout<<4<<"\n";return;
}

int main(){
    IOS;
    int t;cin>>t;
    while(t--)solve();
    return 0;
}
