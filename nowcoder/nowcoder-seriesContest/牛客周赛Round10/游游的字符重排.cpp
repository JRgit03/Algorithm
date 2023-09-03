#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
using namespace std;
typedef long long ll;

//3e6 * 10
void solve(){
    string s; cin>>s; sort(s.begin(),s.end());
    int n = s.length() , ans = 0;
    do{
        int f = 1;
        for(int i=1;i<n;i++) 
            f &= (s[i] != s[i-1]);
        ans += f;
    } while (next_permutation(s.begin(),s.end()));
    cout << ans << "\n";
}

int main(){
    IOS;solve();
    return 0;
}
