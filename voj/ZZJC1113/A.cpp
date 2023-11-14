#include <bits/stdc++.h>
using namespace std;

int main(){
    int n; cin>>n;
    vector<string> a(n); for(auto &x : a) cin>>x;
    sort(a.begin(),a.end(),[&](auto &p,auto &q){
        if(p.length() != q.length()) return p.length() > q.length();
        return p > q;
    });
    long long ans = 0;
    vector<int> id = {0,1,2};
    do{
        ans = max(ans,stoll(a[id[0]]+a[id[1]]+a[id[2]]));
    } while (next_permutation(id.begin(),id.end()));
    cout << ans << "\n";
    return 0;
}
