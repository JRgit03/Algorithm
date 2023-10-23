#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
#define int long long
using namespace std;

void solve(){
    typedef pair<int,int> PII;
    int n; cin>>n;
    vector<PII> vec(n);
    for(int i=0;i<n;i++){
        int l,r; cin>>l>>r;
        vec[i] = {l,l+r};
    }
    sort(vec.begin(),vec.end());
    priority_queue<int,vector<int>,greater<int> > heap;
    int ans = 0;
    for(int i=0;i<n;i++){
        int st = vec[i].first;
        int j=i;
        // 进入开始时间相同同时入队
        while(j<n && vec[j].first == st) heap.push(vec[j].second) , j++;
        int bound = j < n ? vec[j].first : LONG_LONG_MAX;
        // 在下一个产品来之前打印
        while(heap.size() && st < bound){
            int ed = heap.top(); heap.pop();
            if(st <= ed){
                st++;
                ans++;
            }
        }
        i = j - 1;
    }
    cout << ans << "\n";
}

signed main(){
    IOS; solve();
    return 0;
}
