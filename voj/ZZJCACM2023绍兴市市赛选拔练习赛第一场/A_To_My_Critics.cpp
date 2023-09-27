#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
using namespace std;
typedef long long ll;

void solve(){
    vector<int> vec(3);
    for(int i=0;i<3;i++) cin>>vec[i];
    sort(vec.begin(),vec.end());
    cout << (vec[1] + vec[2] >= 10 ? "YES" : "NO") << "\n";
}

int main(){
    IOS;
    int t;cin>>t;
    while(t--)solve();
    return 0;
}
