#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
using namespace std;

struct Node{
    int t,d,l;
};

void solve(){
    int n; cin>>n;
    vector<Node> v(n);
    for(int i=0;i<n;i++){
        int t,d,l; cin>>t>>d>>l;
        v[i] = {t,d,l};
    }
    vector<int> id(n); iota(id.begin(),id.end(),0); sort(id.begin(),id.end());
    do{
        int st,ed,f=1;
        for(int i=0;i<n;i++){
            auto [t,d,l] = v[id[i]];
            if(!i){
                st = t , ed = st + l;
            }else{
                if(t >= ed){
                    st = t , ed = st + l;
                }else if(t + d >= ed){
                    st = ed , ed = st + l;
                }else{
                    f = 0; break;
                }
            }
        }
        if(f){
            cout << "YES" << "\n";
            return;
        }
    }while(next_permutation(id.begin(),id.end()));
    
    cout << "NO" << "\n";
    return;
}

int main(){
    IOS;
    int t; cin>>t;
    while(t--) solve();
    return 0;
}
