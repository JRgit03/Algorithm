/*
    题意：给定n个齿轮每个齿轮的半径为ri, n,q,r<=2e5
    询问是否可以通过重新组装n个尺寸的顺序使得最左边齿轮半径：最右边的齿轮半径 = 1 : x
*/
#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define int long long
using namespace std;

#ifdef LOCAL
#include "./debug.h"
#else
#define debug(...) 21
#endif

const int N = 2e5 + 10, up = 4e6;
int n,q;
int a[N];

// AC 33/100
void solve1(){
    sort(a + 1, a + 1 + n);
    while(q--){
        int x; cin>>x;  
        int suc = 0;
        if(n == 1 && x == 1) suc = 1;
        
        for(int i=1;i<=n;i++){
            int l = i + 1, r = n;
            while(l < r){
                int mid = (l + r + 1) >> 1;
                if(a[mid] <= a[i] * x) l = mid;
                else r = mid - 1; 
            }
            if(a[r] == a[i] * x) suc = 1;
        }
        cout << (suc ? "YES" : "NO") << "\n";
    }
}

int b[N];
// AC 100/100
void solve2(){
    sort(a + 1, a + 1 + n);
    for(int i=1;i<=n;i++) b[a[i]] += 1;
    for(int i=1;i<=n;i++){
        if(a[i] == a[i-1]) continue; // 避免卡n^2
        for(int j=a[i];j<=a[n];j+=a[i]){
            if(j == a[i] && b[j] > 1) b[j / a[i]] = 1;
            else if(b[j] > 0) b[j / a[i]] = 1;  
        }
    }
    while(q--){
        int x; cin>>x;
        int suc = 0;
        if(n == 1 && x == 1) suc = 1;
        suc |= b[x];
        cout << (suc ? "YES" : "NO") << "\n";
    }
}

void solve(){
    cin>>n>>q;
    for(int i=1;i<=n;i++) cin>>a[i];
    if(n * q <= up) solve1();
    else solve2();
    // solve2();
}

signed main(){
    IOS;
    solve();
    return 0;
}
