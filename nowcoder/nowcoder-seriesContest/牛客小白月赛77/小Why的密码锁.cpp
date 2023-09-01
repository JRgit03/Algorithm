#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
using namespace std;
typedef unsigned long long ULL;
const int N = 1e6 + 10 , P = 13331;
int n,m,k;
string s;
ULL h[N],p[N];

ULL get(int l,int r){
    return h[r] - h[l-1] * p[r - l + 1];
}

map<ULL,int> cnt;
map<ULL,pair<int,int>> st;

int main(){
    IOS;
    cin>>n>>m>>k;
    cin>>s; s = "?" + s;
    p[0] = 1;
    for(int i=1;i<=n;i++){
        h[i] = h[i-1] * P + s[i];
        p[i] = p[i-1] * P; 
    }
    for(int i=1;i<=n && i+m-1<=n ;i++){
        ULL key = get(i,i+m-1);
        if(!st.count(key) || st[key].second < i){
            st[key] = {i,i+m-1};
            cnt[key]++;
        }
    }
    int ans = 0;
    for(auto &[_,num] : cnt)
        ans += num == k;
    cout << ans << "\n";
    return 0;
}
