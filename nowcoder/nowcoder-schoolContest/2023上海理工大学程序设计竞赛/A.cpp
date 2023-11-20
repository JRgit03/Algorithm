#include <bits/stdc++.h>
using namespace std;

void solve(){
    vector<int> cnt(10),mod(3);
    int n,sum = 0; cin>>n;
    for(int i=0;i<n;i++){
        int x; cin>>x;
        cnt[x]++; mod[x%3]++;
        sum = (sum + x) % 3;
    }
    int sz = 0, ne = 0;
    if(sum == 1){
        if(mod[1] >= 1){
            ne = sz = 1;
        }else{
            ne = sz = 2;
        }
    }else if(sum == 2){
        if(mod[2] >= 1){
            ne = 2; sz = 1;
        }else{
            ne = 1; sz = 2;
        }
    }
    // cout << sum << " " << sz << " " << ne << "\n";
    string ans = "";
    for(int i=0;i<10;i++){
        for(int j=0;j<cnt[i];j++){
            if(sz > 0 && i % 3 == ne){
                sz--;
            }else{
                ans += char(i+'0');
            }
        }
    }
    if(sz > 0 || ans.length() == 0) {
        cout << -1 << "\n";
        return;
    }
    if(ans.size() && ans.back() == '0') ans = "0";
    reverse(ans.begin(),ans.end());
    cout << ans << "\n";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t; cin>>t;
    while(t--)
        solve();
    return 0;
}
