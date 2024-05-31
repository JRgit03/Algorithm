/**
 * I x 向集合中插入一个字符串 x
 * Q x 询问一个字符串在集合中出现了多少次。 
 */
#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;

#ifdef LOCAL
#include "./debug.h"
#else
#define debug(...) 21
#endif

const int N = 1e5 + 10;
int m;

int son[N][26], idx;
int cnt[N * 26];

void insert(string s){
    int p = 0;
    for(int i=0;i<s.length();i++){
        int u = s[i] - 'a';
        if(!son[p][u]) son[p][u] = ++idx;
        p = son[p][u];
    }
    cnt[p] += 1;
}

int query(string s){
    int p = 0;
    for(int i=0;i<s.length();i++){
        int u = s[i] - 'a';
        if(!son[p][u]) return 0;
        p = son[p][u];
    }
    return cnt[p];
}

void solve(){
    cin>>m; 
    while(m--){
        char op; string s; cin>>op>>s;
        if(op == 'I') insert(s);
        else cout << query(s) << "\n";
    }    
}

signed main(){
    IOS;
    solve();
    return 0;
}
