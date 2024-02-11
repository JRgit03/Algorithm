#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e5 + 10;
int n; // maxn = 100000
string s;
int cnt[N][10];

int getHash(int x){
    int t = 0, base = 1;
    for(int i=0;i<10;i++,base*=2) t += cnt[x][i] * base;
    return t;
}

signed main(){
    cin>>s; n = s.length(); s = " " + s;
    for(int i=1;i<=n;i++){
        cnt[i][s[i] - '0'] += 1;
        for(int j=0;j<10;j++) cnt[i][j] = (cnt[i-1][j] + cnt[i][j]) & 1;
    }
    map<int,map<int,int>> mp;
    mp[0][0] += 1;
    int ans = 0;
    for(int i=1;i<=n;i++){
        int cur = getHash(i) , x;
        ans += mp[cur][i & 1];
        for(int j=0;j<10;j++) {
            x = (cur >> j) & 1;
            ans += mp[cur + (x ? -1 : 1) * (1 << j)][((i & 1) + 1) & 1];
        }  
        mp[cur][i & 1] += 1;
    }
    cout << ans << "\n";
    return 0;
}
