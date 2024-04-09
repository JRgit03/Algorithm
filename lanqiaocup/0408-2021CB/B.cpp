#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define int long long
using namespace std;

int max(int a,int b) { return (a > b ? a : b);}
int min(int a,int b) { return (a < b ? a : b);}

const int N = 1e6 + 10;

void solve(){
    int n; cin>>n;
    int l = 0, r = n;
    while(l < r){
        int mid = (l + r) >> 1;
        if(mid + (mid - 1) * mid / 2 >= n) r = mid;
        else l = mid + 1;
    }
    cout << r << "\n";
}

signed main(){
    IOS; solve();
    return 0;
}

