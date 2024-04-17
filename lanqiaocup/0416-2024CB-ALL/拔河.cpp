#include <bits/stdc++.h> 
#define IOS ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define int long long 
using namespace std;
 
int max(int a,int b){return a > b ? a : b;}
int min(int a,int b){return a < b ? a : b;}
 
const int N = 1e3 + 10;
int n;
int s[N];
 
inline int sum(int l,int r){
    return s[r] - s[l-1];
}
 
// AC 27 
void bf(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>s[i]; s[i] += s[i-1];
    }
    int ans = 1e18;
    for(int l1=1;l1<=n;l1++){
        for(int r1=l1;r1<=n;r1++){
            for(int l2=r1+1;l2<=n;l2++){
                for(int r2=l2;r2<=n;r2++){
                    ans = min(ans, abs(sum(l1,r1) - sum(l2,r2)));
                }
            }
        }
    }
    cout << ans << "\n";
}

// AC 100 
void solve(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>s[i]; s[i] += s[i-1];
    }
    multiset<int> st;
    for(int l=1;l<=n;l++)
        for(int r=l;r<=n;r++)
            st.insert(sum(l,r));
    int ans = 1e18;
    for(int r=1;r<=n;r++){
        for(int rr=r;rr<=n;rr++){
            st.erase(st.lower_bound(sum(r,rr)));
        }
        for(int l=1;l<=r;l++){
            auto it = st.lower_bound(sum(l, r));
            if(it != st.end()){
                int res = abs(sum(l, r) - (*it));
                ans = min(ans, res);
            }
            if(it != st.begin()){
                --it;
                int res = abs(sum(l, r) - (*it));
                ans = min(ans, res);
            }
        }
    } 
    cout << ans << "\n";
     
}
 
signed main(){
    IOS;
    //bf();
    solve();
    return 0;
} 
 
/*
5
10 9 8 12 14
*/
