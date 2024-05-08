//https://www.dotcpp.com/oj/problem3245.html
#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;

#ifdef LOCAL
#include "./debug.h"
#else
#define debug(...) 21
#endif

const int N = 210, M = 1e6 + 10;
int n;
string s[N];
int son[M][26],idx;
int cnt[M];

void insert(string &str){
    int p = 0;
    for(int i=0;i<str.length();i++){
        int u = str[i] - 'a';
        if(!son[p][u]) son[p][u] = ++idx;
        p = son[p][u];
        cnt[p]++;
    }
}

void remove(string &str){
    int p = 0;
    for(int i=0;i<str.length();i++){
        int u = str[i] - 'a';
        if(!son[p][u]) return;
        p = son[p][u];
        cnt[p]--;
    }
}

int query(string &str){
    int res = 0;
    int p = 0;
    for(int i=0;i<str.length();i++){
        int u = str[i] - 'a';
        if(!son[p][u]) return res;
        p = son[p][u];
        res += cnt[p];
    }
    return res;
}

// O(n^3logn)
void solve(){
    cin>>n;
    for(int i=0;i<n;i++) {
        cin>>s[i];
        insert(s[i]);
    }
    int sum = 0;
    for(int i=0;i<n;i++) {
        remove(s[i]);
        sum += query(s[i]);
        insert(s[i]);
    } 
    sum /= 2;
    int ans = sum;
    for(int i=0;i<n;i++){
        remove(s[i]);
        int cur = sum - query(s[i]);
        for(int j=0;j<s[i].length();j++){
            for(char c='a';c<='z';c++){
                swap(s[i][j], c);
                ans = max(ans, cur + query(s[i]));
                swap(s[i][j], c);
            }
        }
        insert(s[i]);
    }
    cout << ans << "\n";
}

signed main(){
    IOS;
    solve();
    return 0;
}
