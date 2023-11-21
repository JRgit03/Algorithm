#include <bits/stdc++.h>
using namespace std;

int main(){
    int n; cin>>n;
    string s; cin>>s;
    vector<int> f(26,0);
    for(int i=0;i<n;i++){
        int j=i;
        while(j<n && s[j] == s[i]) j++;
        f[s[i]-'a'] = max(f[s[i]-'a'],j-i);
        i = j - 1;
    }
    int ans = 0;
    for(int i=0;i<26;i++) ans += f[i];
    cout << ans << "\n";
    return 0;
}
