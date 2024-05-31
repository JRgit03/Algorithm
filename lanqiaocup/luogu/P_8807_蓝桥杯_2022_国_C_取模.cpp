#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define int long long
using namespace std;

int max(int a,int b){return a > b ? a : b;}
int min(int a,int b){return a < b ? a : b;}

const int N = 1e6 + 10;
int t; 
int n,m;

// 假设法
// 假设在范围1<=x<y<m内不存在x,y使得 n % x == n % y
// 因为 n % 1 = 0, 则 n % 2 = 1, n % 3 = 2, n % 4 == 3....... 
void solve(){
    cin>>n>>m;
    if(m >= 1000) {
        cout << "Yes" << "\n";
        return;
    }
    for(int i=1;i<=m;i++){
        if(n % i != i - 1){
            cout << "Yes" << "\n";
            return;
        }
    }
    cout << "No" << "\n";
    return;
}

signed main(){
    IOS;
    int t; cin>>t;
    while(t--) solve();
    return 0;
}
