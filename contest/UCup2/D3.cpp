#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
using namespace std;

// i row j col
void solve(){
    int n,m; cin>>n>>m;
    int f = n > m ? 1 : 0; if(f) swap(n,m);
    if(n == m){
        if(n != 1){
            cout << n * 2 - 2 << "\n";
        }else{
            cout << 1 << "\n";
        }
        if(!f){
            for(int i=1;i<=n;i++) cout << i << " " << 1 << "\n";
            for(int i=2;i<=n-1;i++) cout << i << " " << m << "\n";
        }else{
            for(int i=1;i<=n;i++) cout << 1 << " " << i << "\n";
            for(int i=2;i<=n-1;i++) cout << m << " " << i << "\n";
        }
    }else{
        if(n & 1){
            cout << m - (n + 1) + 2 * n << "\n";
            for(int i=1;i<=n;i++) {
                if(!f){
                    cout << i << " " << 1 << "\n";
                    cout << i << " " << m << "\n";
                }else{
                    cout << 1 << " " << i << "\n";
                    cout << m << " " << i << "\n";
                }
            }
            for(int j=(n+1)/2+1;j<=m-(n+1)/2;j++){
                if(!f){
                    cout << (n+1)/2 << " " << j << "\n";
                }else{
                    cout << j << " " << (n+1)/2 << "\n";
                }
            }
        }else{
            cout << (m - (n/2+2) + 1 - (n/2+2) + 1 + 2 - 1) / 2 * 2 + 2 * n << "\n";
            for(int i=1;i<=n;i++) {
                if(!f){
                    cout << i << " " << 1 << "\n";
                    cout << i << " " << m << "\n";
                }else{
                    cout << 1 << " " << i << "\n";
                    cout << m << " " << i << "\n";
                }
            }
            for(int j=(n/2+2);j<=m-(n/2+2)+1;j+=2){
                if(!f){
                    cout << n / 2 << " " << j << "\n";
                    cout << n / 2 + 1 << " " << j << "\n";
                }else{
                    cout << j << " " << n / 2 << "\n";
                    cout << j  << " " << n / 2 + 1 << "\n";
                }
            }
        }
    }
}

int main(){
    IOS; solve(); return 0;
}
