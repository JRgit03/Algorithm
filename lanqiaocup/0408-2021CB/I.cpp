#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define int long long
using namespace std;

int max(int a,int b) { return (a > b ? a : b);}
int min(int a,int b) { return (a < b ? a : b);}

const int N = 1e5 + 10;

int n,m;
int a[N];

void solve(){
    cin>>n>>m;
    for(int i=1;i<=n;i++) a[i] = i;
    while(m--){
        int op,k; cin>>op>>k;
        if(op == 0) sort(a + 1, a + 1 + k, greater<int>());
        else sort(a + 1 + k - 1, a + 1 + n);
    } 
    for(int i=1;i<=n;i++) cout << a[i] << " "; cout << "\n";
}   

signed main(){
    IOS; solve();
    return 0;
}

