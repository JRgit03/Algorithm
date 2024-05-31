#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define int long long
using namespace std;

#ifdef LOCAL
#include "./debug.h"
#else
#define debug(...) 21
#endif

const int N = 1e5 + 10;
int n,m;
int a[N];

int tr[N];
int lowbit(int x){return x & -x;}
void add(int x,int c){for(int i=x;i<=n&&i>0;i+=lowbit(i)) tr[i] += c;}
int sum(int x){int res = 0; for(int i=x;i>0;i-=lowbit(i)) res += tr[i]; return res;}

void solve(){
    cin>>n>>m;
    for(int i=1;i<=n;i++) {
        cin>>a[i]; add(i, a[i] - a[i-1]);
    }
    while(m--){
        char op; cin>>op;
        if(op == 'Q'){
            int x; cin>>x;
            cout << sum(x) << "\n";
        }else{
            int l,r,c; cin>>l>>r>>c;
            add(l, c); add(r+1, -c);
        }
    }
}

signed main(){
    IOS;
    solve();
    return 0;
}
