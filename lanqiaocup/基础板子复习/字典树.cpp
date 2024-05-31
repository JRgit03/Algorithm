/*
    题意：n个模式串,m次询问t是模式串s前缀的数量
*/
#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;

#ifdef LOCAL
#include "./debug.h"
#else
#define debug(...) 21
#endif

const int N = 3e6 + 10;
int n,m;
int cnt[N];
int son[N][62], idx;

int get(char c){
    if(c >= '0' && c <= '9') return c - '0' + 52;
    return ((c >= 'a' && c <= 'z') ? c - 'a' : c - 'A' + 26);
}

void insert(string &s){
    int p = 0;
    for(int i=0;i<s.length();i++){
        int u = get(s[i]);
        if(!son[p][u]) son[p][u] = ++idx;
        p = son[p][u];
        cnt[p] += 1;
    }
}

int query(string &s){
    int p = 0;
    for(int i=0;i<s.length();i++){
        int u = get(s[i]);
        if(!son[p][u]) return 0;
        p = son[p][u];
    }
    return cnt[p];
}

void solve(){
    for(int i=0;i<=idx;i++) {
        cnt[i] = 0;
        for(int j=0;j<62;j++) son[i][j] = 0;
    }
    idx = 0;
    
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        string s; cin>>s; insert(s);
    }
    while(m--){
        string t; cin>>t; cout << query(t) << "\n";
    }
}

signed main(){
    IOS;
    int t; cin>>t;
    while(t--) solve();
    return 0;
}
