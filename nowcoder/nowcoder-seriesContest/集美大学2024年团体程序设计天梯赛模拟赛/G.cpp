#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 11;
int n = 5;
string s[N];
int a[N],b[N];
vector<string> ans;

void solve(){
    for(int i=1;i<=n;i++) cin>>s[i]>>a[i]>>b[i];
    // cout << 27 * 27 * 27 << "\n";
    for(char c1 = 'A'; c1 <= 'Z'; c1++){
        for(char c2 = 'A'; c2 <= 'Z'; c2++){
            for(char c3 = 'A'; c3 <= 'Z'; c3++){
                // char c1 = 'A', c2 = 'A', c3 = 'A';
                int suc = 1; 
                vector<char> c = {c1, c2, c3}; //for(auto x : c) cout << x << " "; cout << "\n";
                set<char> st = {c1, c2, c3}; //for(auto x : st) cout << x << ""; cout << "\n";
                for(int i=1;i<=5;i++){
                    int sz1 = 0, sz2 = 0;
                    for(int j = 0; j < 3;j++){
                        sz1 += (st.count(s[i][j]));
                        sz2 += (s[i][j] == c[j]);
                    }
                    // cout << "ck: " << i << " " << sz1 << " " << sz2 << "\n";
                    suc &= (sz1 == a[i] && sz2 == b[i]);
                }
                if(suc){
                    string str = "";
                    str += c1;
                    str += c2;
                    str += c3;
                    ans.push_back(str);
                }
            }
        }
    }
    cout << ans.size() << "\n";
    for(auto &str : ans) cout << str << "\n";
}

signed main(){
    solve();
    return 0;
}
