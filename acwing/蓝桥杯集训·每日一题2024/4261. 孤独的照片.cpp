#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 5e5 + 10;
int n;
string s;

int l[N]; // l[i]表示第i头牛左边连续的不同种类的牛的数量
int r[N];

// 枚举第i个牛的品种恰好有一个头的方案数
// = 左边选1~l[i] * 右边选1~r[i] + 左边选0右边2~r[i] + 左边选2~l[i]右边0
void solve(){   
    cin>>n>>s; s = "?" + s;
    int g = 0, h = 0;
    for(int i=1;i<=n;i++){
        if(s[i] == 'G') l[i] = h, h = 0, g += 1;
        else if(s[i] == 'H') l[i] = g, g = 0, h += 1; 
    }
    g = 0, h = 0;
    for(int i=n;i>0;i--){
        if(s[i] == 'G') r[i] = h, h = 0, g += 1;
        else if(s[i] == 'H') r[i] = g, g = 0, h += 1; 
    }
    int ans = 0;
    for(int i=1;i<=n;i++){
        int L = l[i], R = r[i];
        ans += L * R + max(0LL, R-1) + max(0, L-1);
    }
    cout << ans << "\n";
}

signed main(){
    solve();
    return 0;
}
