#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
using namespace std;
typedef long long ll;

void solve(){
    int n,m; cin>>n>>m;
    cout << (m == 1 ? 0 : min(n+1,m)) << "\n";
    for(int i=1;i<=min(n,m-1);i++){
        for(int j=0;j<m;j++){
            cout << (i + j) % m << " ";
        }
        cout << "\n";
    }
    for(int i=0;i<n-(m-1);i++){
        for(int j=0;j<m;j++){
            cout << (j + m - 1) % m << " ";
        }
        cout << "\n";
    }
    
}

int main(){
    IOS;
    int t;cin>>t;
    while(t--)solve();
    return 0;
}
