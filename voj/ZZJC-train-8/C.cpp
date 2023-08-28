#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
using namespace std;
const int N = 10;

struct Node{
    int x,y,z;
}vec[N];

int get(Node a,Node b){
    return (b.z-a.z)*(b.z-a.z)+(b.y-a.y)*(b.y-a.y)+(b.x-a.x)*(b.x-a.x);
}

void solve(){
    for(int i=1;i<=8;i++){
        int a,b,c;cin>>a>>b>>c; vec[i] = {a,b,c};
    }
    map<int,int> mp;
    for(int i=1;i<=8;i++)
        for(int j=i+1;j<=8;j++)
            mp[get(vec[i],vec[j])]++;
    
    if(mp.size()!=3) {cout<<"NO"<<"\n";return;}

    int tar[] = {0,12,12,4};  int idx = 1;
    
    for(auto [len,cnt] : mp)
        if(cnt != tar[idx++]){
            cout<<"NO"<<"\n";return;
        }
    
    cout<<"YES"<<"\n";return;
}

int main(){
    IOS;
    int t;cin>>t;while(t--)solve();
    return 0;
}
