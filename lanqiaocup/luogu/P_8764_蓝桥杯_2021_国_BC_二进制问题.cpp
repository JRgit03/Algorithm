#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define int long long
using namespace std;

#ifdef LOCAL
#include "./debug.h"
#else
#define debug(...) 21
#endif

int max(int a,int b){return a > b ? a : b;}
int min(int a,int b){return a < b ? a : b;}

const int N = 1e6 + 10;
int n,k;

// 暴力AC 30/100
void solve1(){
    int ans = 0;
    for(int i=1;i<=n;i++){
        int x = i, cnt = 0;
        while(x > 0){
            if(x & 1) cnt += 1;
            x /= 2;
        }
        if(cnt == k) ans += 1;
    }
    cout << ans << "\n";
}


int m; 
int b[110];
int memo[110][110];

// f(i,mask,isLimit,isNum) 完整参数
// f(i,cnt,isLimit) 前i位,1的个数cnt个,isLimit是否受到限制 从高位往低位填数
int f(int i,int cnt,int isLimit){
    if(i == m) return cnt == k;
    if(!isLimit && memo[i][cnt] != -1) return memo[i][cnt];
    
    int res = 0;
    int up = (isLimit ? b[i] : 1);
    for(int d=0;d<=up;d++)
        res += f(i + 1, cnt + (d == 1), isLimit & (d == up));
    
    if(!isLimit) memo[i][cnt] = res;
    return res;
}

void solve2(){
    memset(memo, -1, sizeof memo);
    vector<int> vec; while(n > 0){
        vec.push_back(n & 1);
        n /= 2;
    } 
    reverse(vec.begin(), vec.end());  debug(vec);
    m = vec.size(); for(int i=0;i<m;i++) b[i] = vec[i];
    cout << f(0, 0, 1) << "\n";
}

void solve(){
    cin>>n>>k;
    if(n <= 1000000 && k <= 10) solve1();    
    else solve2();
}

signed main(){
    IOS;
    solve();
    return 0;
}
