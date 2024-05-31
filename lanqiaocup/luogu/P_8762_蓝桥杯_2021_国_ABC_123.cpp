#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define int long long
using namespace std;

int max(int a,int b){return a > b ? a : b;}
int min(int a,int b){return a < b ? a : b;}

const int N = 1e6 + 10;

int calc(int n){
    if(n == 0) return 0;
    int l = 1, r = 1e9;
    while(l < r){
        int mid = (l + r + 1) >> 1;
        if((1 + mid) * mid / 2 <= n) l = mid;
        else r = mid - 1;
    }
    int sum = 0;
    int x = 1, y = n - (1 + r) * r / 2;
    sum += (x + y) * y / 2;
    sum += ((1 + r) * r / 2 + r * (r + 1) * (2 * r + 1) / 6) / 2;
    return sum;
}

void solve(){
    int l, r; cin>>l>>r;
    cout << calc(r) - calc(l-1) << "\n";
}

signed main(){
    IOS;
    int t; cin>>t;
    while(t--) solve();
    return 0;
}
