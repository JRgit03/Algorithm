#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve(){
    int n;cin>>n;
    vector<int> vec(n);
    for(int i=0;i<n;i++) cin>>vec[i];
    sort(vec.begin(),vec.end());
    if(vec[0]!=1) {cout << "NO" << "\n"; return; }

    ll sum = 1;
    for(int i=1;i<n;i++){
        if(vec[i] <= sum) sum += vec[i];
        else {cout << "NO" << "\n"; return; }
    }
    cout << "YES" << "\n"; return;
}

int main(){
    int t;cin>>t;
    while(t--)solve();
    return 0;
}
