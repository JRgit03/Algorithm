#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
#define int long long 
using namespace std;
const int N = 1e5 + 10 , M = 25;
int n;
int s[N];
int w[M][2];

signed main(){
    IOS;
    cin>>n;
    for(int i=0;i<=20;i++) w[i][0] = 1; // s[0] = 0;
    for(int i=1;i<=n;i++) {
        cin>>s[i];
        s[i] ^= s[i-1];
    }
    for(int i=1;i<=n;i++){
        for(int j=0;j<M;j++){
            w[j][(s[i]>>j)&1] += 1;
        }
    }
    int ans = 0;
    for(int i=0;i<=20;i++) ans += (1<<i) * w[i][0] * w[i][1];
    cout << ans << "\n";
    return 0;
}

// 异或字段和 -> 异或前缀和
// s[i] ^ s[j] = 1 
// => 按位拆分不影响答案的结果
// => 选择两个下标 异或前缀和结果为1 
//    根据乘法原理 每个0和每个1匹配对答案都有贡献
