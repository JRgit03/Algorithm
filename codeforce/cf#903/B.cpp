#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
#define int long long
using namespace std;
typedef long long ll;

int sz[4] = {3,4,5,6};

void solve(){
    vector<int> v(3); for(auto &x : v) cin>>x; sort(v.begin(),v.end());
    int sum = accumulate(v.begin(),v.end(),0LL);
    bool f = false;
    for(int i=0;i<4;i++){
        int tar = sum / sz[i];
        if(sum % sz[i]) continue;
        int cnt = 0 , op = i;
        priority_queue<int> heap;
        for(int j=0;j<3;j++) heap.push(v[j]);
        while(heap.size() && op){
            int t = heap.top(); heap.pop();
            if(t == tar) cnt++;
            else if(t > tar) {
                cnt++; op--;
                heap.push(t-tar);
            }
        }
        while(heap.size()){
            int t = heap.top(); heap.pop();
            if(t == tar) cnt++;
        }
        // cout << i << " " << cnt << " " << sz[i] << "\n";
        f |= (cnt == sz[i]);
    }
    cout << (f ? "YES" : "NO") << "\n";
}

signed main(){
    IOS;
    int t;cin>>t;
    while(t--)solve();
    return 0;
}
