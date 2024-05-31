#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define int long long
using namespace std;

#ifdef LOCAL
#include "./debug.h"
#else
#define debug(...) 21
#endif

const int N = 2e5 + 10, maxn = 2e5;
int n;
int a[N];
int ans[N];

int num = 1;
set<int> s; 

int primse[N],cnt;
int st[N];

void solve(){  
    cin>>n;
    for(int i=2;i<=n;i++){
        if(!st[i]) primse[cnt++] = i;
        for(int j=0;primse[j]<=n/i;j++){
            st[primse[j] * i] = 1;
            if(i % primse[j] == 0) break;
        }
    }
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=2;i<=n;i++) if(a[i] > a[i - 1]) {
        cout << -1 << "\n";
        return;
    }
    for(int i=1;i<=n;i++){
        if(i == 1) ans[i] = a[i], s.insert(a[i]);
        else{
            if(a[i] != 1){
                if(ans[i - 1] % a[i] == 0){
                    if(s.count(a[i])){
                        cout << -1 << "\n";
                        return;
                    }
                    ans[i] = a[i], s.insert(a[i]);
                }else{
                    cout << -1 << "\n";
                    return;
                }
            }else{
                for(int k=1;k<cnt;k++){
                    if(!s.count(primse[k])){
                        ans[i] = primse[k];
                        i += 1;
                        s.insert(primse[k]);
                    }
                }
                debug(i, num);
                while(i <= n && num <= n){
                    if(!s.count(num)){
                        ans[i] = num;
                        i += 1;
                    }
                    num += 1;
                }
            }
        }
    }
    for(int i=1;i<=n;i++) cout << ans[i] << " ";
}


// WA
signed main(){
    IOS;
    solve();
    return 0;
}
