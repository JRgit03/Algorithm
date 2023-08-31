#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
using namespace std;
typedef long long ll;

int len = 10;
string s = "codeforces";

void solve(){
    ll k; cin>>k;
    ll ans = 1;
    vector<int> cnt(10,1);
    for(int i=0;ans<k;i=(i+1)%len){
        ans = ans / cnt[i] * (cnt[i] + 1); 
        cnt[i]++;
    }
    string str = "";
    for(int i=0;i<len;i++)
        for(int j=0;j<cnt[i];j++)
            str = str + s[i];
    cout << str << "\n";
}

int main(){
    IOS;
    int t = 1;
    while(t--)solve();
    return 0;
}
