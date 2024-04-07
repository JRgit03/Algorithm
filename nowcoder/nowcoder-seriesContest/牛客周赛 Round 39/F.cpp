#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve(){
    int ans = 0;
    int n; cin>>n;
    set<int> s01,s10,s00;
    string a,b; cin>>a>>b;
    for(int i=1;i<=n;i++){
        int c1 = a[i - 1] - '0', c2 = b[i - 1] - '0';
        if(c1 && c2) ans += 1;
        else if(c1 && !c2) s10.insert(i);
        else if(!c1 && c2) s01.insert(i);
        else s00.insert(i);
    }
    int q; cin>>q;
    while(q--){
        char c; int x,y; cin>>c>>x>>y;
        if(c == 'A'){
            if(s01.size()){
                auto itl = s01.lower_bound(x);
                if(itl != s01.end() && (*itl) <= y){
                    auto itr = s01.upper_bound(y);
                    for(auto it = itl; it != itr; it++){
                        ans += 1;
                    }
                    s01.erase(itl, itr);
                }
            }
            if(s00.size()){
                auto itl = s00.lower_bound(x);
                if(itl != s00.end() && (*itl) <= y){
                    auto itr = s00.upper_bound(y);
                    for(auto it = itl; it != itr; it++){
                        s10.insert((*it));
                    }
                    s00.erase(itl, itr); 
                }
            }
        }else{
            if(s10.size()){
                auto itl = s10.lower_bound(x);
                if(itl != s10.end() && (*itl) <= y) {
                    auto itr = s10.upper_bound(y);
                    for(auto it = itl; it != itr; it++){
                        ans += 1;
                    }
                    s10.erase(itl, itr);
                }
            }
            if(s00.size()){
                auto itl = s00.lower_bound(x);
                if(itl != s00.end() && (*itl) <= y) {
                    auto itr = s00.upper_bound(y);
                    for(auto it = itl; it != itr; it++){
                        s01.insert((*it));
                    }
                    s00.erase(itl, itr); 
                }
            }
        }
        cout << ans << "\n";
    }
}

signed main(){
    solve();
    return 0;
}
