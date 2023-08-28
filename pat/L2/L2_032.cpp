#include <bits/stdc++.h>
using namespace std;
const int N = 1e3 + 10;
int n,m,q;
int stk[N];

void solve(){
    int tt = 0 , cur = 1;
    bool f = true;
    for(int i=1;i<=n;i++){
        int x;cin>>x;
        if(x==cur)cur++;
        else {
            stk[++tt] = x;
            if(tt > m){
               f = false;
            }
        }
        while(tt>0 && stk[tt] == cur) cur++ , tt--;
    }
    if(cur==n+1 && f)puts("YES");
    else puts("NO");
}

int main(){
    cin>>n>>m>>q;
    while(q--)solve();
    return 0;
}
