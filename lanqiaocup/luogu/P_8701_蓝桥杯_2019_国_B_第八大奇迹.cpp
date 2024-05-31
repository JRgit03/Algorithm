#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
// #define int long long
using namespace std;

int max(int a,int b){return a > b ? a : b;}
int min(int a,int b){return a < b ? a : b;}

const int N = 1e5 + 10, up = 1e8;
int n,m;
int a[N];

// AC 40/100
void solve1(){
    while(m--){
        char c; int l,r; cin>>c>>l>>r;
        if(c == 'C') a[l] = r;
        else {
            priority_queue<int, vector<int>, greater<int> > q;
            for(int i=l;i<=r;i++){
                q.push(a[i]);
                if(q.size() > 8) q.pop();
            }
            if(q.size() < 8) cout << 0 << "\n";
            else cout << q.top() << "\n";
        }
    }
}

void solve2(){
    
}

void solve(){
    cin>>n>>m;
    if(n * m <= up) solve1();
    else solve2();    
}

signed main(){
    IOS;
    solve();
    return 0;
}
