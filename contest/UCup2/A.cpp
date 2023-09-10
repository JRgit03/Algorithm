#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
using namespace std;

void solve(){
    int n; cin>>n;
    string s; cin>>s; s = "s" + s;
    set<char> st = {'s','p','b','u'};
    map<char,vector<int>> mp;
    for(int i=1;i<=n;i++){
        char c = s[i];
        if(st.count(c)) mp[c].push_back(i);
    }
    int s1 , p , b , s2 , u;
    int ans = INT_MAX;
    for(int i=1;i<=n;i++){
        char c = s[i];
        if(c == 'b'){
            int l = 0 , r = mp['s'].size() - 1;
            while(l < r){
                int mid = l + r >> 1;
                if(mp['s'][mid] >= i) r = mid;
                else l = mid + 1;
            }
            if(mp['s'][r] <= i) continue;
            s2 = mp['s'][r];

            l = 0 , r = mp['u'].size() - 1;
            while(l < r){
                int mid = l + r >> 1;
                if(mp['u'][mid] >= s2) r = mid;
                else l = mid + 1;
            }
            if(mp['u'][r] <= s2) continue;
            u = mp['u'][r];

            l = 0 , r = mp['p'].size() - 1;
            while(l < r){
                int mid = l + r + 1 >> 1;
                if(mp['p'][mid] < i) l = mid;
                else r = mid - 1;
            }
            if(mp['p'][r] >= i) continue; 
            p = mp['p'][r];

            l = 0 , r = mp['s'].size() - 1;
            while(l < r){
                int mid = l + r + 1>> 1;
                if(mp['s'][mid] < p) l = mid;
                else r = mid - 1;
            }
            if(mp['s'][r] >= p) continue;
            s1 = mp['s'][r];

            ans = min(ans ,s2+u-p-s1-6);
        }
    }
    cout << ans << "\n";
}

int main(){
    IOS; solve();
    return 0;
}
