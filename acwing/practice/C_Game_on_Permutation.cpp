#include <bits/stdc++.h>
#define int long long
#define IOS ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;
const int N = 3e5 + 10;
int a[N];
int win[N];
// 在点i下棋 考虑前面是否存在必胜状态 
// 如果存在必胜状态或者前面没有选择的状态 则i是必败态

void solve(){
    int n;cin>>n;
    for(int i=1;i<=n;i++) win[i] = 0 , cin>>a[i];
    int minx , wmin = 1e9;
    for(int i=1;i<=n;i++){
        if(i==1) minx = a[i];
        else{
            if(a[i] < minx) minx = a[i];
            else if(a[i] < wmin) win[i] = 1 , wmin = a[i];
        }
    }    
    cout << accumulate(win+1,win+1+n,0) << "\n";
}

signed main(){
    IOS;
    int t;cin>>t;while(t--)solve();
    return 0;
}