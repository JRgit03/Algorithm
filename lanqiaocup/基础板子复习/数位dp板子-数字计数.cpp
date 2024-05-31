/*
    题意：给定两个正整数𝑎和𝑏，求在 [a,b] 中的所有整数中，每个数码(digit)各出现了多少次。
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

int v;
int m; string s;
int memo[22][22];

int f(int i,int cnt,int isLimit,int isNum){
    if(i == m) return (isNum ? cnt : 0);
    if(!isLimit && isNum && memo[i][cnt] != -1) return memo[i][cnt];
    
    int res = 0;
    if(!isNum) res = f(i + 1, cnt, 0, 0);
    
    int up = (isLimit ? s[i] - '0' : 9);
    for(int d = 1 - isNum; d <= up; d++){
        res += f(i + 1, cnt + (d == v), isLimit & (d == up), 1);
    }

    if(!isLimit && isNum) memo[i][cnt] = res;
    return res;
}

int check(int x){
    int res = 0;
    while(x) res += (x % 10 == v), x /= 10;
    return res;
}

int calc(int x){
    memset(memo, -1, sizeof memo);
    s = to_string(x); m = s.length();
    return f(0, 0, 1, 0);
}

void solve(){
    cin>>a>>b;
    for(int i=0;i<10;i++){
        v = i; cout << calc(b) - calc(a) + check(a) << " ";
    }   
}

signed main(){
    IOS;
    solve();
    return 0;
}
