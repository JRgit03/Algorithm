#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n;cin>>n;
    vector<int> vec(n+1);
    for(int i=1;i<=n;i++) cin>>vec[i];

    vector<int> v;
    for(int i=1;i<=n/2;i++){
        if(vec[i]!=vec[n-i+1]){
            v.push_back(abs(vec[n-i+1]-vec[i]));
        } 
    }
    
    if(!v.size()) {cout << 0 << "\n"; return;}

    sort(v.begin(),v.end());

    int d = v[0];
    for(int i=1;i<v.size();i++)
        if(v[i] % d != 0){
            cout << 1 << "\n"; return;
        } 
    cout << d << "\n"; return;
}

int main(){
    int t;cin>>t;
    while(t--)solve();
    return 0;
}
