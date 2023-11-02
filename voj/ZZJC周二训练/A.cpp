#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
int n,m;
int a[N];
int ans[N];
int main(){
    cin>>n>>m;
    for(int i=0;i<m;i++) {
        int x;cin>>x;
        a[x] = 1; 
    }
    int t = 0; for(int i=n;i>=1;i--) ans[i] = (a[i] ? t = 0 : ++t);
    for(int i=1;i<=n;i++) cout << ans[i] << "\n";
    return 0;
}
