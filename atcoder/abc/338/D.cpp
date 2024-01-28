// 差分
#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main(){
    int n,m; cin>>n>>m;
    vector<int> x(m),b(n+1); // b 差分数组 下标从0开始的每座桥
    for(auto &v : x){
        cin>>v; v -= 1;
    }
    auto dist = [&](int from,int to){
        if(from <= to) return to - from;
        return n - (from - to);
    };
    auto add = [&](int from,int to,int c){
        if(from <= to){ // 1 -> 3 
            b[from] += c;
            b[to] -= c;
        }else{ // 3 -> 1
            b[from] += c;
            b[n] -= c;
            b[0] += c;
            b[to] -= c;
        }
    };
    //单独考虑每一段路程对影响的桥的贡献
    for(int i=0;i<m-1;i++){ 
        add(x[i], x[i+1], dist(x[i+1], x[i])); 
        add(x[i+1], x[i], dist(x[i], x[i+1]));
    }
    // n = 5 => 0,1,2,3,4 route = 1->3(点从0开始)  点01之间的桥编号为0 点12之间的桥编号为1 ... 
    // 1走到3距离可以为 2 / 3
    // 断开桥1或者桥2 => 距离为2的路线对桥3,4,0的贡献为2
    // 同理断开桥3或者桥4或者桥0 => 距离为3的路线对桥1,2的贡献为3
    int ans = LONG_LONG_MAX;
    for(int i=0;i<n;i++){
        b[i+1] += b[i];
        ans = min(ans, b[i]);
    }
    cout << ans << '\n';
    return 0;
}
