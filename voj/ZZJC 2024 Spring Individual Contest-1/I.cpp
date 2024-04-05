#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define int long long
using namespace std;

int max(int a,int b) {return (a > b ? a : b);}
int min(int a,int b) {return (b > a ? a : b);}

void solve(){
    int n; cin>>n;
    cout << (1LL << (n - 1)) << "\n";
}

signed main(){
    IOS;
    solve();
    return 0;
}
