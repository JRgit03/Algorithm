#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define int long long
using namespace std;

int max(int a,int b) {return (a > b ? a : b);}
int min(int a,int b) {return (b > a ? a : b);}

int a,b,n,m,h;

int check(int x){
    return n / b * (b - a) + (n + m - x) / b * (h - b) >= x;
}

void solve(){
    cin>>a>>b>>n>>m>>h;
    int l = 0, r = m - 1;
    while(l < r){
        int mid = (l + r + 1) >> 1;
        if(check(mid)) l = mid;
        else r = mid - 1;
    }
    cout << n + m - r << "\n";
}

signed main(){
    IOS;
    int t; cin>>t;
    while(t--) solve();
    return 0;
}
