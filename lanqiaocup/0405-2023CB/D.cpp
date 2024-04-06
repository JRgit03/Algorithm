#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0); 
#define int long long
using namespace std;
const int N = 11;
int n,suc;
int t[N],d[N],l[N];

void solve(){
    suc = 0;
    cin>>n;
    for(int i=1;i<=n;i++) cin>>t[i]>>d[i]>>l[i];
    vector<int> id(n+1); for(int i=1;i<=n;i++) id[i] = i;
    do{
        int f = 1, cur = 0;
        for(int i=1;i<=n;i++){
            int x = t[id[i]], y = t[id[i]] + d[id[i]];
            if(y < cur) f = 0;
            else {
                cur = max(cur, x);
                cur = cur + l[id[i]];
            }
        }
        suc |= f;
    }while(next_permutation(id.begin() + 1, id.end()));
    cout << (suc ? "YES" : "NO") << "\n";        
}

signed main(){
    IOS; 
    int t; cin>>t;
    while(t--) solve();
    return 0;
} 

/*
2
3
0 100 10
10 10 10
0 2 20
3
0 10 20
10 10 20
20 10 20
*/

