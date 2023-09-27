#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
using namespace std;
typedef long long ll;

void solve(){
    int n;cin>>n;
    vector<int> a(n),b;
    for(auto &x : a) cin>>x;
    b = a; sort(b.begin(),b.end());
    for(int i=0;i<n;i++)
        if((a[i] & 1 )!= (b[i] & 1)){
            cout << "NO" << "\n";
            return;
        }
    cout << "YES" << "\n";
    return;
}

int main(){
    IOS;
    int t;cin>>t;
    while(t--)solve();
    return 0;
}
