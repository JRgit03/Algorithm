#include <bits/stdc++.h>
using namespace std;

int main(){
    int n; cin>>n;
    vector<pair<int,int>> vec = {{0,0}};
    for(int i=0;i<n;i++){
        int l,r; cin>>l>>r;
        vec.push_back({l,r});
    }
    int ans = 0;
    for(int i=1;i<vec.size();i++) 
        ans = max(ans, vec[i].second - vec[i-1].first);
    cout << ans << "\n";
    return 0;
}
