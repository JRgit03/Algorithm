#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
using namespace std;
typedef long long ll;

void solve(){
    int n; cin>>n;
    vector<int> a(n+1);
    for(int i=1;i<=n;i++) cin>>a[i];
    int cnt = 0;
    for(int i=1;i<=n;i++) 
        if(a[i] != i && a[i-1] == i-1)
            cnt++;
    cout << (cnt >= 2 ? 2 : cnt) << "\n";
}

int main(){
    IOS;
    int t;cin>>t;
    while(t--)solve();
    return 0;
}
