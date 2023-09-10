#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
using namespace std;
typedef long long ll;

void solve(){
    int n,m; cin>>n>>m;
    int ans = 0 , flag = 0;
    if(n > m) swap(n,m) , flag = 1;
    if(m % n != 0) {
        ans = (m + n - 1) / n * n;
        cout << ans << "\n";
        for(int i=1;i<=m;i+=n){
            for(int j=1;j<=n;j++){
                if(!flag) cout << j << " " << i << "\n";
                else cout << i << " " << j << "\n";
            }
        }
    }
    else {
        int a = m / n , b = m % n;
        if(a == 1)  {
            ans = a * n + max(n-2,0);
            cout << ans << "\n";
            for(int i=1;i<=m;i+=n){
                for(int j=1;j<=n;j++){
                    cout << j << " " << i << "\n";
                }
            }
            for(int i=2;i<=n-1;i++){ // n 为 row
                if(!flag) cout << i << " " << m << "\n";
                else cout << m << " " << i << "\n";
            }
        }
        else{
            ans = a * n + (n - 2 == 1 ? 2 : (n-2+1) / 2 * 2);
            cout << ans << "\n";
            for(int i=1;i<=m;i+=n){
                for(int j=1;j<=n;j++){
                    if(i != m - n + 1){
                        if(!flag) cout << j << " " << i << "\n";
                        else cout << i << " " << j << "\n";
                    }else{
                        if(!flag) cout << j << " " << m << "\n";
                        else cout << m << " " << j << "\n";
                    }
                }
            }
            
            for(int i=2;i<=n-1;i+=2){
                if(!flag){
                    cout << i << " " << m-n << "\n";
                    cout << i << " " << m-n+1 << "\n";
                }else{
                    cout << m-n  << " " << i << "\n";
                    cout << m-n+1  << " " << i << "\n";
                }
            }
        }
    }
}

int main(){
    IOS; solve();
}