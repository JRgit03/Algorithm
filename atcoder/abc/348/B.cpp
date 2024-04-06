#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve(){
    int n; cin>>n;
    vector<array<int,2>> p(n);
    for(int i=0;i<n;i++) cin>>p[i][0]>>p[i][1];
    for(int i=0;i<n;i++){
        vector<array<int,2>> vec;
        for(int j=0;j<n;j++){
            if(i == j) continue;
            int dx = p[i][0] - p[j][0], dy = p[i][1] - p[j][1];
            vec.push_back({dx * dx + dy * dy, j+1});
        }
        sort(vec.begin(), vec.end(), [&](auto &a, auto &b){
           return a[0] != b[0] ? a[0] > b[0] : a[1] < b[1]; 
        });
        cout << vec[0][1] << "\n";
    }
}

signed main(){
    solve();
    return 0;
}
