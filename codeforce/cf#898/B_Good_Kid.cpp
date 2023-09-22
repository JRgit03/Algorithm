#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
using namespace std;
typedef long long ll;

void solve(){
    int n; cin>>n;
    int cnt0 = 0 , mul = 1;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        int x; cin>>x;
        mul *= x; a[i] = x;
        cnt0 += x == 0;
    }
    if(cnt0 > 1) {
        cout << 0 << "\n"; 
    }else if(cnt0 == 1){
        int mul = 1;
        for(int i=0;i<n;i++) 
            mul *= (a[i] == 0 ? 1 : a[i]);
        cout << mul << "\n"; 
    }else{
        int ans = mul;
        for(int i=0;i<n;i++)
            ans = max(ans,mul/a[i]*(a[i]+1));
        cout << ans << "\n";
    }
}

int main(){
    IOS;
    int t;cin>>t;
    while(t--)solve();
    return 0;
}
