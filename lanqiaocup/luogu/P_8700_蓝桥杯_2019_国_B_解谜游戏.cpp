#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define int long long
using namespace std;

int max(int a,int b){return a > b ? a : b;}
int min(int a,int b){return a < b ? a : b;}

const int N = 1e6 + 10;

// 考虑周期 操作一二同时旋转 相对不变
void solve(){
    string a,b,c; cin>>a>>b>>c;
    int suc = 1;
    for(int i=0;i<4;i++){
        map<char,int> cnt;
        cnt[a[i]] += 1, cnt[a[i+4]] += 1, cnt[a[i+8]] += 1;
        cnt[b[i]] += 1, cnt[b[i+4]] += 1;
        cnt[c[i]] += 1;
        if(cnt['Y'] != 1 || cnt['R'] != 2 || cnt['G'] != 3) suc = 0;
    }
    cout << (suc ? "YES" : "NO") << "\n";
}

signed main(){
    IOS;
    int t; cin>>t;
    while(t--) solve();
    return 0;
}
