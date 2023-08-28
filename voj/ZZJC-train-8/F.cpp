#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
using namespace std;

void solve(){
    int n,m;cin>>n>>m;
    if(n>=m) {cout<<(n-m)<<"\n";return;}
    queue<tuple<int,int,int> > q;
    q.push({n,m,0});

    while(q.size()){
        auto [x,y,op] = q.front(); q.pop();
        if(y%x==0){
            cout<<op<<"\n";return; 
        }
        q.push({x-1,y,op+1});
        q.push({x,y+1,op+1});
    }
}

int main(){
    IOS;
    int t;cin>>t;
    while(t--)solve();
    return 0;
}
