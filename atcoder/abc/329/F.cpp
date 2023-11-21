#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 10;
int n,q;
set<int> st[maxn];

int main(){
    cin>>n>>q;
    for(int i=1;i<=n;i++){
        int x; cin>>x;
        st[i].insert(x);
    }
    while(q--){
        int a,b; cin>>a>>b;
        if(st[a].size() > st[b].size()) swap(st[a],st[b]);
        for(auto x : st[a]) st[b].insert(x); st[a].clear();
        cout << st[b].size() << "\n";   
    }
    return 0;
}
