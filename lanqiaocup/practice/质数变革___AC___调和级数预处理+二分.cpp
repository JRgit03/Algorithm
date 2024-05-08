#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define int long long
using namespace std;

#ifdef LOCAL
#include "./debug.h"
#else
#define debug(...) 21
#endif

const int N = 1e6 + 10, up = 1000000;
int n,m;
int a[N];
int st[N];
int primes[N], cnt;
int b[N];
int c[N];


void solve(){
    for(int i=2;i<=up;i++){
        if(!st[i]) primes[cnt++] = i;
        for(int j=0;primes[j]<=up / i;j++){
            st[i * primes[j]] = 1;
            if(i % primes[j] == 0) break;
        }
    }
    //debug(cnt); // 78498
    //for(int i=0;i<100;i++) debug(primes[i]);
    cin>>n>>m; 
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=0;i<m;i++){
        int op,k,x; cin>>op>>k>>x;
        if(op == 1) b[k] += x;
        else b[k] -= x;
    }
    for(int i=1;i<=n;i++)
        for(int j=i;j<=n;j+=i)
            c[j] += b[i];
    //for(int i=1;i<=n;i++) debug(c[i]);
    for(int i=1;i<=n;i++){
        if(c[i] == 0) cout << a[i] << " ";
        else if(c[i] > 0){
            int l = 0, r = cnt - 1;
            while(l < r){
                int mid = (l + r) >> 1;
                if(primes[mid] > a[i]) r = mid;
                else l = mid + 1;
            }
            if(primes[r] > a[i]){
                if(r + c[i] - 1 < cnt){
                    cout << primes[r + c[i] - 1] << " ";
                }else{
                    cout << 1 << " ";
                }
            }else{
                cout << 1 << " ";
            }
        }else{
            c[i] = -c[i];
            int l = 0, r = cnt - 1;
            while(l < r){
                int mid = (l + r + 1) >> 1;
                if(primes[mid] < a[i]) l = mid;
                else r = mid - 1;
            }
            if(primes[r] < a[i]){
                if(r - c[i] + 1 >= 0){
                    cout << primes[r - c[i] + 1] << " ";
                }else{
                    cout << 0 << " ";
                }
            }else{
                cout << 0 << " ";
            }
        }
    }
}

signed main(){
    IOS;
    solve();
    return 0;
}
