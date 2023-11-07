#include <bits/stdc++.h>
#define x first
#define y second
using namespace std;
const int maxn = 3e5 + 10;
int n;
int main(){
    cin>>n;
    vector<pair<int,int>> vec(n);
    for(int i=0;i<n;i++) {
        int a,b; cin>>a>>b;
        vec[i] = {a,b};
    }
    sort(vec.begin(),vec.end(),[&](auto &a,auto &b){
       return a.y > b.y;
    });
    int ans = vec[0].y;
    for(int i=1;i<n;i++) ans = max(ans,vec[0].y + (vec[i].x == vec[0].x ? vec[i].y / 2 : vec[i].y));
    cout << ans << "\n";
    return 0;
}
