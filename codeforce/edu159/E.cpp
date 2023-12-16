#include <bits/stdc++.h>
#define int long long
using namespace std;
const int maxn = 1e6 + 10;
int n;
int ans;

string s[maxn];

int son[maxn][26];
int cnt[maxn];
int idx;

void insert(string &s){
    int p = 0;
    for(int i=0;s[i];i++){
        int u = s[i] - 'a';
        if(!son[p][u]) son[p][u] = ++idx;
        p = son[p][u];
        cnt[p]++;
    }
}

void query(string &s){
    int p = 0;
    for(int i=0;s[i];i++){
        int u = s[i] - 'a';
        if(!son[p][u]) break;
        p = son[p][u];
        ans -= 2 * cnt[p];
    }
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n; 
    for(int i=0;i<n;i++){
        cin>>s[i]; insert(s[i]);
        ans += 2 * n * s[i].length();
    }
    for(int i=0;i<n;i++){
        reverse(s[i].begin(),s[i].end());
        query(s[i]);
    }
    cout << ans << "\n";
    return 0;
}
