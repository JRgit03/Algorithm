#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;

void solve(){
    int minodd=2e9;
    int n;cin>>n;vector<int> a(n);for(auto &x:a) {
        cin>>x;if(x&1)minodd = min(minodd,x);
    }
    sort(a.begin(),a.end());

    vector<int> odd;

    int f = a[0] & 1;
    for(int i=1;i<n;i++){
        if((a[i] & 1 ) == f)continue;
        else{
            if(a[i] - minodd <= 0){
                cout << "NO" << "\n";return;
            }
        }
    }
    cout << "YES" << "\n";return;
}

int main(){
    IOS;int t;cin>>t;while(t--)solve();return 0;
}
