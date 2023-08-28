#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n;cin>>n;
    string s;cin>>s;
    map<pair<char,char>,int> cnt;
    for(int i=1;i<s.length();i++){
        cnt[{s[i-1],s[i]}]++;
    }
    cout << (int)cnt.size() << "\n";
}

int main(){
    int t;cin>>t;while(t--)solve();return 0;
}
