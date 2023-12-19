#include <bits/stdc++.h>
using namespace std;

void solve(){
    int id,n; cin>>id>>n;
    priority_queue<int> big;
    priority_queue<int,vector<int>,greater<int>()> small;
    vector<int> ans;
    for(int i=1;i<=n;i++){
        int x; cin>>x;
        // 对顶堆的核心-调整
        if(big.size() == small.size()){
            small.push(x);
            int t = small.top(); small.pop();
            big.push(t);
        }else{
            big.push(x);
            int t = big.top(); big.pop();
            small.push(t);
        }
        // 插完奇数个的时候输出当前数组的中位数
        if(i & 1) ans.push_back(big.top()); 
    }
    cout << id << " " << (n+1)/2 << "\n";
    for(int i=0;i<ans.size();i++){
        cout << ans[i] << " ";
        if((i+1)%10==0) cout << "\n";
    }
    if(ans.size() % 10 != 0) cout << "\n";
}

int main(){
    int t; cin>>t;
    while(t--)
        solve();
    return 0;
}
