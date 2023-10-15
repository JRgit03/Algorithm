#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
#define int long long
using namespace std;
typedef long long ll;
const int N = 5e5 + 10;
int n,m;
string s[N],t;
int pre[N],suf[N]; // pre[i]表示与t匹配的最大前缀 suf[i]表示与t匹配的最大后缀
int sufSum[N]; // s[x]表示 suf>=x的个数
int calc(string &s,string &t,int type){
    int k = 0;
    for(int i=0;i<s.length();i++){
        if(k >= m) break;
        if(s[i] == t[k]) k++;
    }
    return k;
}

signed main(){
    IOS;
    cin>>n>>t; m = t.length();
    for(int i=1;i<=n;i++){
        cin>>s[i]; 
        pre[i] = calc(s[i],t,1);
    }
    reverse(t.begin(),t.end());
    for(int i=1;i<=n;i++){
        reverse(s[i].begin(),s[i].end());
        suf[i] = calc(s[i],t,0);
        sufSum[suf[i]] += 1;
    }
    for(int i=m;i>=0;i--) sufSum[i] += sufSum[i+1];
    int ans = 0;
    for(int i=1;i<=n;i++) ans += sufSum[m-pre[i]];
    cout << ans << "\n";
    return 0;
}
