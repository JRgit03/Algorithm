/**
 * 对顶堆维护中位数
 * https://www.luogu.com.cn/problem/SP16254
 */
#include <bits/stdc++.h>
using namespace std;

void solve(){
    priority_queue<int> big;
    priority_queue<int,vector<int>,greater<int> > small;
    int n; while(cin>>n){
        if(!n) break;
        if(n > 0){
            if(big.size() == small.size()){ //插入大根堆 
                small.push(n);
                int t = small.top(); small.pop();
                big.push(t);
            }else{ // 插入到小根堆
                big.push(n);
                int t = big.top(); big.pop();
                small.push(t);
            }
        }else if(n == -1){
            cout << big.top() << "\n";
            if(big.size() > small.size()){
                big.pop();
            }else{
                big.pop();
                int t = small.top(); small.pop();
                big.push(t);
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}
