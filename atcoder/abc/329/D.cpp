#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 10;
int n,m;
int maxx,ans;
int cnt[maxn];
int main(){
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int x; cin>>x;
        cnt[x] += 1;
        if(cnt[x] > maxx){
            maxx = cnt[x];
            ans = x;
        }else if(cnt[x] == maxx && x < ans){
            ans = x;
        }
        cout << ans << "\n";
    }
    return 0;
}
