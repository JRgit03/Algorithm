#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n;cin>>n;
    vector<int> f(n+1);
    string s;cin>>s; s = "?" + s;
    map<char,int> mp;
    for(char ch = 'a' ; ch <= 'z' ; ch++) mp[ch] = -1;
    for(int i=1;i<=n;i++){
        if(i==1){
            mp[s[i]] = 1;
            f[i] = 1;
        }else{
            if(mp[s[i]]==-1){
                f[i] = mp[s[i]] = 1 ^ f[i-1];
            }else{
                f[i] = mp[s[i]];
                if(f[i] == f[i-1]){
                    cout << "NO" << "\n"; return;
                } 
            }
        }
    }
    cout << "YES" << "\n"; return;
}

int main(){
    int t;cin>>t;
    while(t--)solve();
    return 0;
}
