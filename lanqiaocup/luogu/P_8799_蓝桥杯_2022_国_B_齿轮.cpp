#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define int long long
using namespace std;

int max(int a,int b){return a > b ? a : b;}
int min(int a,int b){return a < b ? a : b;}

const int N = 2e5 + 10, up = 4e6, maxn = 2e5;
int n,m;
int r[N];

void solve1(){
    while(m--){
        map<int,int> mp;
        int k; cin>>k;
        int suc = 0;
        for(int i=1;i<=n;i++){
            suc |= (mp.count(r[i] * k));
            suc |= (r[i] % k == 0 && mp.count(r[i] / k)); 
            mp[r[i]] = 1;
        }
        cout << (suc ? "YES" : "NO") << "\n";
    }
}

int b[N];
int ans[N];
void solve2(){
    sort(r + 1, r + 1 + n);
    for(int i=1;i<=n;i++) b[r[i]] += 1;
    for(int i=1;i<=n;i++){
        if(r[i] == r[i-1]) continue;
        for(int j=r[i];j<=maxn;j+=r[i]){
            if(j == r[i] && b[j] > 1) ans[j / r[i]] = 1;
            else if(j != r[i] && b[j] > 0) ans[j / r[i]] = 1;
        }
    }
    while(m--){
        int k; cin>>k;
        cout << (ans[k] ? "YES" : "NO") << "\n";
    }
}

void solve(){
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>r[i];
    if(n * n <= up && n * m <= up) solve1();
    else solve2();    
}

signed main(){
    IOS;
    solve();
    return 0;
}
