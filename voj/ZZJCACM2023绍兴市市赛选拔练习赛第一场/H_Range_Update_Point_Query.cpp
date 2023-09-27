#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
#define int long long
using namespace std;
typedef long long ll;
const int N = 2e5 + 10;
int n,q;
int a[N];
int tr[N];

int lowbit(int x){
    return x & -x;
}

int get(int x){
    int res = 0;
    while(x) res += x % 10 , x /= 10;
    return res;
}

void add(int x,int c){
    for(int i=x;i<=n;i+=lowbit(i)) tr[i] += c;
}

int sum(int x){
    int res = 0;
    for(int i=x;i;i-=lowbit(i)) res += tr[i];
    return res;
}

void solve(){
    cin>>n>>q;
    for(int i=1;i<=n;i++) {
        cin>>a[i]; tr[i] = 0;
    }
    for(int i=0;i<q;i++){
        int op,l,r,x; cin>>op;
        if(op == 1){
            cin>>l>>r;
            add(l,1); add(r+1,-1);
        }else{
            cin>>x; int cnt = sum(x) , cur = a[x];
            while(cnt > 0 && cur >= 10){
                cur = get(cur);
                cnt -= 1;
            }
            cout << cur << "\n";
        }
    }
}

signed main(){
    IOS;
    int t;cin>>t;
    while(t--)solve();
    return 0;
}
