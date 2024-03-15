#include <bits/stdc++.h>
using namespace std;
const int N = 1e2 + 10, M = 1e5 + 10;
int n,k,a[N];
int dp[M]; 

// 取石子
// 有 K 个石子，双方轮流取石子，每一次取的石子数必须是集合 A 中的一个数，双方都以最优策略行动，判断先手必胜还是后手必胜。
// 当一名玩家无法操作时，另一名玩家获胜。

// dp[i] 表示 当前石子堆还剩下i个石子,当前操作者的状态(必胜态/必败态)
// dp[0] = 0 没有石子则必败
// dp[i]必胜 当且仅当 i >= a[j] && dp[i - a[j]] 必败 即必胜态可由必败态转移

void solve(){
    cin>>n>>k;
    for(int i=1;i<=n;i++) cin>>a[i];
    dp[0] = 0;
    for(int i=1;i<=k;i++){
        for(int j=1;j<=n;j++){
            if(i - a[j] < 0) continue;
            dp[i] |= !dp[i - a[j]];
        }
    }    
    cout << (dp[k] ? "First" : "Second") << "\n";
}

signed main(){
    solve();
    return 0;
}
