#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
int n,l,r;
int q[N],hh,tt;
string s;

int f(int k){
    vector<int> cnt(26);
    hh=0,tt=-1;
    int sz = 0 , ans = 0;
    for(int i=0;i<n;i++){
        if(++cnt[s[i]-'a'] == 1) sz++; q[++tt] = i;
        while(hh <= tt && sz > k){
            if(--cnt[s[q[hh]]-'a'] == 0) sz--; 
            ans++;
            hh++;
        }
        if(sz == k) {ans++;}
    }
    while(hh <= tt && sz >= k){
        if(--cnt[s[q[hh++]]-'a'] == 0) sz--; 
        ans += sz == k;
    }

    return ans;
}

int main(){
    cin>>n>>l>>r>>s;
    int ans = 0;
    for(int i=l;i<=r;i++) {
        ans += f(i);
    }
    cout << ans << "\n";
    return 0;
}
