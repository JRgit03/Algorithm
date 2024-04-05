#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define int long long
using namespace std;

int max(int a,int b) {return (a > b ? a : b);}
int min(int a,int b) {return (b > a ? a : b);}

const int N = 5e5 + 10, P = 131;
typedef unsigned long long ULL;
ULL h[N],h2[N],p[N];

ULL gethash(int l,int r){
    return h[r] - h[l-1] * p[r-l+1];
}

int n;
int l1,l2,d;
string a,b;
string a2,a3;

int suc;
ULL tar;
int f(string &s){
    for(int i=1;i<=n;i++) h[i] = h[i - 1] * P + s[i - 1];
    unordered_set<int> st; int k = 0;
    while(!st.count(k)){
        st.insert(k);
        ULL res = gethash(1, n-k) + gethash(n-k+1, n) * p[n - k];
        if(res == tar) return 1;
        k = (k + d) % n;
    }
    st.clear(); k = 0;
    while(!st.count(k)){
        st.insert(k);
        ULL res = gethash(1, n-k) + gethash(n-k+1, n) * p[n - k];
        if(res == tar) return 1;
        k = ((k - d) % n + n) % n;
    }
    return 0;
} 

void solve(){
    suc = 0;
    cin>>a>>b; n = a.length();
    cin>>l1>>l2; if(l1 > l2) swap(l1, l2); d = l2 - l1;
    p[0] = 1;
    for(int i=1;i<=n;i++){
        h2[i] = h2[i - 1] * P + b[i - 1];
        p[i] = p[i - 1] * P;
    }
    tar = h2[n];
    if(f(a)) {
        cout << "yes" << "\n";
        return;
    }
    a2 = a;
    reverse(a2.begin(), a2.begin() + l1);
    reverse(a2.begin() + l1, a2.end());
    if(f(a2)){
        cout << "yes" << "\n";
        return;
    }
    a3 = a;
    reverse(a3.begin(), a3.begin() + l2);
    reverse(a3.begin() + l2, a3.end());
    if(f(a3)){
        cout << "yes" << "\n";
        return;
    }
    cout << "no" << "\n";
    return;
}

signed main(){
    IOS;
    int t; cin>>t;
    while(t--) solve();
    return 0;
}
