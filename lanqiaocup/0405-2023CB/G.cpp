#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0); 
#define int long long
using namespace std;

int max(int a,int b){return (a > b ? a : b); }
int min(int a,int b){return (a < b ? a : b); }

void solve(){
    int k; cin>>k;
    string s; cin>>s;
    char c1,c2; cin>>c1>>c2;
    vector<int> v1, v2;
    int n = s.length(); 
    for(int i=0;i<n;i++){
        if(s[i] == c1) v1.push_back(i);
        if(s[i] == c2) v2.push_back(i);
    }
    int ans = 0;
    for(auto &x : v1){
        int l = 0, r = v2.size() - 1;
        while(l < r){
            int mid = l + r >> 1;
            if(v2[mid] - x + 1 >= k) r = mid;
            else l = mid + 1;
        }
        if(v2[r] - x + 1 >= k) ans += v2.size() - r; 
    }
    cout << ans << "\n";
}

signed main(){
    IOS; solve();
    return 0;
} 

/*
4
abababdb a b
*/

