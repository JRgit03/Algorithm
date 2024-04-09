#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define int long long
using namespace std;

int max(int a,int b) { return (a > b ? a : b);}
int min(int a,int b) { return (a < b ? a : b);}

const int N = 1e6 + 10;

// n^3暴力枚举 
// 存x的所有因子 x的因子个数不会很多 

void solve(){
    int x = 2021041820210418;
    set<__int128> v; 
    for(int i=1;i<=sqrt(x);i++){
        if(x % i == 0){
            v.insert(i);
            v.insert(x/i);
        }
    }
//    cout << v.size() << "\n"; // 128
    int ans = 0;
    for(auto &a : v)
        for(auto &b : v)
            for(auto &c : v)
                if(a * b * c == x) 
                    ans += 1;
    cout << ans << "\n";
}

signed main(){
    IOS; solve();
    return 0;
}

/*
2 1
3 3
17 1
131 1
2857 1
5882353 1
*/

