#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10;
int n; 
string s1,s2;
int v1[N],v2[N];
int b[N];

void solve(){
    cin>>n>>s1>>s2;
    for(int i=1;i<=n;i++) v1[i] = s1[i-1] - 'a';
    for(int i=1;i<=n;i++) v2[i] = s2[i-1] - 'a';
    for(int i=1;i<=n;i++) b[i] = ((v2[i] - v1[i]) % 26 + 26) % 26;
    int ans = 0;
    for(int i=1;i<=n;i++){
        if(b[i] == 0) continue;
        int j = i + 1;
        while(j <= n && b[j] == b[i]) j += 1;
        ans += 1;
        i = j - 1;
        if(j <= n && b[j] == 0) {
            ans += 1;
            i += 1;
        }
    }
    cout << ans << "\n";
}

signed main(){
    solve();
    return 0;
}
