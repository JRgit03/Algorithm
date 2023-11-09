#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 10;
int q[maxn],len,last;

void solve(){
    int n,m; cin>>n>>m;
    map<int,int> mp; 
    set<int> st;
    vector<int> a(n),b;
    for(int i=0;i<n;i++) {
        cin>>a[i];
        st.insert(a[i]);
    }
    for(int i=0;i<m;i++){
        int x;cin>>x;
        if(st.count(x)) mp[x]++;
        else b.push_back(x);
    }
    sort(b.begin(),b.end(),greater<int>());
    int cnt = 0;
    for(int i=0;i<n;i++){
        while(cnt < b.size() && b[cnt] > a[i]) cout << b[cnt++] << " ";
        cout << a[i] << " ";
        if(mp.count(a[i]) && mp[a[i]] > 0){
            int sz = mp[a[i]];
            while(sz--){
                cout << a[i] << " ";
            }
            mp[a[i]] = 0;
        }
    }
    while(cnt < b.size()) cout << b[cnt++] << " "; 
    cout << "\n";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t; cin>>t;
    while(t--)  
        solve();
    return 0;
}
