/*
    Windy 定义了一种 Windy 数：不含前导零且相邻两个数字之差至少为 2 的正整数被称为 Windy 数。
    Windy 想知道，在 A和B之间，包括 A和B，总共有多少个 Windy 数？ A <= B <= 2e9
*/
#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define int long long
using namespace std;

#ifdef LOCAL
#include "./debug.h"
#else
#define debug(...) 21
#endif

int a,b;
int m;
string s;
int memo[22][22];

int f(int i,int pre,int isLimit,int isNum){
    if(i == m) return isNum;
    if(!isLimit && isNum && memo[i][pre] != -1) return memo[i][pre];
    
    int res = 0;
    if(!isNum) res = f(i + 1, pre, 0, 0);
    
    int up = (isLimit ? s[i] - '0' : 9);
    for(int d=1-isNum;d<=up;d++){
        if(abs(d - pre) >= 2){
            res += f(i + 1, d, isLimit & (d == up), 1);
        }
    }

    if(!isLimit && isNum) memo[i][pre] = res;
    return res;
}

int check(int x){
    string t = to_string(x);
    for(int i=1;i<t.length();i++) if(abs(t[i] - t[i-1]) < 2) return 0;
    return 1;
}

int calc(int val){
    memset(memo, -1, sizeof memo);
    s = to_string(val); m = s.length();
    return f(0, 11, 1, 0);
}

void solve(){
    cin>>a>>b;
    cout << calc(b) - calc(a) + check(a) << "\n";
}

signed main(){
    IOS;
    solve();
    return 0;
}
