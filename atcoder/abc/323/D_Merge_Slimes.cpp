#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
#define int long long
using namespace std;

void solve(){
    map<int,int> cnt;
    int n; cin>>n;
    set<int> st;
    for(int i=0;i<n;i++){
        int s,c; cin>>s>>c;
        cnt[s] = c;
        st.insert(s);
    }
    int ans = 0;
    while(st.size()){
        int t = *st.begin(); st.erase(st.begin());
        int sz = cnt[t];
        if(sz & 1) ans += 1;
        for(int j=1;j<=30;j++) 
            if((sz>>j)&1){
                cnt[t*(1<<j)] += 1;
                st.insert(t*(1<<j));
            }
    }
    cout << ans << "\n";
}

signed main(){
    IOS; solve();
    return 0;
}

// #include <bits/stdc++.h>
// #define IOS ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
// #define int long long
// using namespace std;

// void solve(){
//     map<int,int> cnt;
//     int n; cin>>n;
//     priority_queue<int,vector<int>,greater<int> > heap;
//     for(int i=0;i<n;i++){
//         int s,c; cin>>s>>c;
//         cnt[s] = c;
//         heap.push(s);
//     }
//     int ans = 0;
//     while(heap.size()){
//         int t = heap.top(); heap.pop();
//         int sz = cnt[t]; cnt[t] = 0;
//         if(!sz) continue;
//         if(sz & 1) ans += 1;
//         for(int j=1;j<=30;j++) 
//             if((sz>>j)&1){
//                 cnt[t*(1<<j)] += 1;
//                 heap.push(t*(1<<j));
//             }
//     }
//     cout << ans << "\n";
// }

// signed main(){
//     IOS; solve();
//     return 0;
// }

