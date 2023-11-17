#include <bits/stdc++.h>
using namespace std;

void solve(){
    string s; cin>>s;
    int m; string l,r; cin>>m>>l>>r;
    int p = 0;
    for(int i=0;i<m;i++){
        int q = p; // temp
        if(l[i] > r[i]) swap(l[i],r[i]);
        for(char c = l[i]; c <= r[i]; c++){
            int k = s.find(c,p);
            if(k == -1){
                cout << "YES" << "\n";
                return;
            }
            q = max(q, k+1); //greedy
        }
        p = q;
    }
    cout << "NO" << "\n";
    return;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin>>t;
    while(t--)
        solve();
    return 0;
}
