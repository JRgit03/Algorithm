#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
#define ONLINE_JUDGE  
using namespace std;
typedef long long ll;

void solve(){
    int n,m;  cin>>n>>m;
    string s,t; cin>>s>>t;
    int ans = INT_MAX; 
    vector<int> vec;
    for(int i=0;i+n-1<m;i++){
        vector<int> tmp;
        for(int k=0;k<n;k++){
            if(s[k] != t[i+k]){
                tmp.push_back(k);
            }
        }
        if(tmp.size() < ans){
            ans = tmp.size(); 
            vec = tmp;
        }
    }
    cout << ans << "\n";
    for(auto &x : vec) cout << x+1 << " ";
}

int main(){
    #ifndef ONLINE_JUDGE
        freopen("E:/in.txt","r",stdin);
        freopen("E:/out.txt","w",stdout);
    #endif
    IOS; solve();
    return 0;
}
