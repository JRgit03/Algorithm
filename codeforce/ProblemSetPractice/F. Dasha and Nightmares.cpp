#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;
const int N = 5e6 + 10;
int n;
vector<int> tmp;
map<int,int> mp;
int cnt[N][26];

int main(){
    IOS;
    cin>>n;
    for(int i=1;i<=n;i++){
        string s; cin>>s;
        for(int j=0;j<s.length();j++)
            cnt[i][s[j] - 'a'] += 1;
    }
    long long ans = 0;
    for(int c=0;c<26;c++){
        tmp.clear(); mp.clear();
        for(int i=1;i<=n;i++){
            if(cnt[i][c]) continue;
            int w = 0;
            for(int j=0;j<26;j++) {
                if(cnt[i][j] & 1) {
                    w ^= (1 << j);   
                }
            }
            tmp.push_back(w); mp[w] += 1;
        }
        for(auto &x : tmp){
            ans += mp[((1 << 26) - 1 ^ (1 << c)) - x];
        }
    }
    cout << ans / 2 << "\n";
    return 0;
}
