#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10;

int n,m;
char op[maxn];
int t[maxn];

int calc(int k,int now){
    for(int i=1;i<=n;i++){
        int x = (t[i] >> k) & 1;
        if(op[i] == 'A') now &= x;
        else if(op[i] == 'O') now |= x;
        else now ^= x;
    }
    return now;
}

int main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++) {
        string s; cin>>s>>t[i]; op[i] = s[0];    
    }
    int val = 0, ans = 0; // val：当前填的值 ans：答案
    for(int i=30;i>=0;i--){
        int res0 = calc(i,0), res1 = calc(i,1); // res0表示填0的结果 res1表示填1的结果
        if(val + (1 << i) <= m){ // 当前为可填 0 / 1
            if(res0 >= res1) { // 填0的结果 >= 填1的结果 => 填0更优
                ans |= (res0 << i);
            }else{ // 填0的结果 < 填1的结果 => 填1更优
                val |= (res1 << i);
                ans |= (res1 << i);
            }
        }else{ // 当前位置只能填0
            ans |= (res0 << i);
        }
    }
    cout << ans << "\n";
    return 0;
}
