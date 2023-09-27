#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
using namespace std;
typedef long long ll;
const int N = 2e5 + 10 , Mod = 998244353;
int n;
string s;
int fact[N];

void init(){
    fact[0] = 1;
    for(int i=1;i<=200000;i++) fact[i] = 1LL * fact[i-1] * i % Mod; 
}

// 排列 * 组合
void solve(){
    cin>>s; n = s.length();
    vector<int> num; int ans = 1 , sz = 0;
    for(int i=0;i<n;i++){
        int j=i;
        while(j<n && s[i] == s[j]) j += 1;
        num.push_back(j-i);  ans = 1LL * ans * max(1, j - i) % Mod;
        sz += j - i - 1;
        i = j - 1;
    }
    cout << n - num.size() << " " << 1LL * ans * fact[sz] % Mod << "\n";
}

int main(){
    IOS;
    int t;cin>>t; init();
    while(t--)solve();
    return 0;
}
