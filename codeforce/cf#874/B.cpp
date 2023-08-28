#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;

struct Node{
    int id,val,res;
};

void solve(){
    int n,k;cin>>n>>k;
    vector<Node> a(n);
    vector<int> b(n);
    for(int i=0;i<n;i++){
        int x;cin>>x;
        a[i]={i,x,0};
    }
    for(int i=0;i<n;i++)cin>>b[i];
    sort(a.begin(),a.end(),[](const Node &p1 , const Node &p2){
        return p1.val < p2.val;
    });
    sort(b.begin(),b.end());
    for(int i=0;i<n;i++){
        a[i].res = b[i];
    }
    sort(a.begin(),a.end(),[](const Node &p1 , const Node &p2){
        return p1.id < p2.id;
    });
    for(int i=0;i<n;i++) cout << a[i].res << " "; cout << "\n";
}

int main(){
    IOS;int t;cin>>t;while(t--)solve();return 0;
}
