#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define int long long
using namespace std;

#ifdef LOCAL
#include "./debug.h"
#else
#define debug(...) 21
#endif

const int N = 1e6 + 10;

void solve(){
    int n; cin>>n;
    priority_queue<int> big;
    priority_queue<int, vector<int>, greater<int> > small;
    for(int i=1;i<=n;i++){
        int x; cin>>x;
        if(big.size() == small.size()){
            small.push(x); 
            int t = small.top(); small.pop();
            big.push(t);
        }else{
            big.push(x);
            int t = big.top(); big.pop();
            small.push(t);
        }
        if(i & 1) cout << big.top() << "\n";
    }
}

signed main(){
    IOS;
    solve();
    return 0;
}

/*
给定一个长度为 N 的非负整数序列 A，对于前奇数项求中位数。

7
1 3 5 7 9 11 6

1
3
5
6

*/
