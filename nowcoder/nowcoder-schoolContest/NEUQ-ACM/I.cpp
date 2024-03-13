#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
#define debug(x) cerr << #x << " = " << (x) << '\n'
using namespace std;
const int N = 2e5 + 10, P = 13331;
int n,m,q;
string str;
string str2;
typedef unsigned long long ULL;
ULL h[N],h2[N],p[N];

ULL gethash(int l,int r,ULL h[]){
    return h[r] - h[l-1] * p[r-l+1];
}

void init(){
    str = "?" + str;
    str2 = "$" + str2;
    p[0] = 1;
    for(int i=1;i<=n;i++){
        h[i] = h[i-1] * P + (str[i] - 'a');
        p[i] = p[i-1] * P;
    }
    for(int i=1;i<=m;i++){
        h2[i] = h2[i-1] * P + (str2[i] - 'a');
    }
}
int a,b,c,d;
// str[a ~ k] ? str2[c ~ c + k - a]
int check(int k){
    return gethash(a,k,h) == gethash(c, c+k-a, h2);
}

void solve(){
    cin>>n>>m>>q;
    cin>>str>>str2;
    init();
    while(q--){
         cin>>a>>b>>c>>d;
        if(gethash(a,b,h) == gethash(c,d,h2)){
            cout << "=" << "\n";
        }else{
            int l = a, r = b;
            while(l < r){
                int mid = l + r + 1 >> 1;
                if(check(mid)) l = mid;
                else r = mid - 1;
            }
            // debug(r);
            if(check(r)){
                if(str[r+1] < str2[c+r-a+1]){
                    cout << "<" << "\n";
                }else{
                    cout << ">" << "\n";
                }
            }else{
                // debug("");
                if(str[a] < str2[c]){
                    cout << "<" << "\n";
                }else{
                    cout << ">" << "\n";
                }
            }
        }
    }
}

signed main(){
    IOS;
    solve();
    return 0;
}
