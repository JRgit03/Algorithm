#include <bits/stdc++.h>
using namespace std;

map<int,int> mp;

void init(){
    int x = 1 , op = 0;
    queue<pair<int,int> > q;
    q.push({x,0});
    while(q.size()){
        auto [a,b] = q.front(); q.pop();
        
        if(mp[a]!=0 || b>40)continue;
        mp[a] = b;
        
        q.push({a*2-1,b+1});
        q.push({a*2+1,b+1});
    }
}

int main(){
    init();
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        if(!mp[n]){
            cout << "-1" << "\n";
        }else{
            cout << mp[n] << "\n";
        }
    }
    return 0;
}
