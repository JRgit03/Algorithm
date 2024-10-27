#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;

int max(int a,int b){ return a > b ? a : b;}
int min(int a,int b){ return a < b ? a : b;}
const int N = 1e6 + 10;
int n,q;
int a[N],b[N];

int primes[N],cnt;
int st[N];

void solve(){
    
    for(int i=2;i<=1000000;i++){
        if(!st[i]) primes[cnt++] = i;
        for(int j=0;primes[j] <= 1000000 / i; j++){
            st[primes[j] * i] = 1;
            if(i % primes[j] == 0) break;
        }
    }
    
    cin>>n>>q;
    for(int i=1;i<=n;i++) cin>>a[i];
    while(q--){
        int op,k,x; cin>>op>>k>>x;
        for(int i=k;i<=n;i+=k) {
            if(op == 1) b[i] += x;
            else b[i] -= x;
        }
    }
    for(int i=1;i<=n;i++){
        int x = b[i];
        if(x == 0) cout << a[i] << " ";
        else if(x > 0){
            int l = 0, r = cnt - 1;
            while(l < r){
                int mid = (l + r) >> 1;
                if(primes[mid] > a[i]) r = mid;
                else l = mid + 1;
            }
            if(primes[r] > a[i]){
                if(r + x - 1 < cnt){
                    cout << primes[r + x - 1] << " ";
                }else{
                    cout << 1 << " ";
                }
            }else{
                cout << 1 << " ";
            }
        }else{
            x = -x;
            int l = 0, r = cnt - 1;
            while(l < r){
                int mid = (l + r + 1) >> 1;
                if(primes[mid] < a[i]) l = mid;
                else r = mid - 1;
            }
            if(primes[r] < a[i]){
                if(r - x + 1 >= 0){
                    cout << primes[r - x + 1] << " ";
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

/*
5 3
2 3 6 9 12
1 2 1
1 2 1
2 3 4

2 7 0 13 12

*/ 

/*
3 1
1 1 1
1 1 1

2 2 2
*/

/*
3 1
1 1 1
2 1 1

0 0 0
*/

/*
1 1
10000000
1 1 1

*/
