#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
#define int long long
using namespace std;

map<int,int> mp = {
    {1,26},
    {2,26},
    {3,10},
    {4,4}
};

int get(char c){
    if(c >= 'a' && c <= 'z') return 1;
    if(c >= 'A' && c <= 'Z') return 2;
    if(c >= '0' && c <= '9') return 3;
    return 4;
}

void solve(){
    string s; cin>>s;
    int n = s.length(); s = "$" + s;
    map<int,int> cnt;
    for(int i=1;i<=n;i++) cnt[get(s[i])] += 1;
    
    int sz = 0;
    for(int i=1;i<=4;i++){
        //cout << i << " " << cnt[i] << "\n";
        sz += cnt[i] >= 1;
    }

    if(sz <= 2){
        cout << 0 << "\n";
        return;
    }

    if(sz == 3){
        int tar = 0;
        for(int i=1;i<=4;i++) 
            if(!cnt[i])
                tar = i;

        int ans = 0;
        for(int i=1;i<=n;i++){
            char c = s[i];
            if(cnt[get(c)] >= 2){
                ans += mp[tar];
            }
        }
        cout << ans << "\n";
    }else{
        int ans = 0;
        for(int i=1;i<=n;i++){
            char c = s[i]; 
            if(cnt[get(c)] > 1){
                ans += 66 - 1;
            }else{
                ans += mp[get(c)] - 1;
            }
        }
        cout << ans << "\n";
    }
    
}

signed main(){
    IOS;
    int t;cin>>t;
    while(t--) solve();
    return 0;
}
