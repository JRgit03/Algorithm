#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 11;
int n;
int vis[N];
string s[N];
string ans = "";

// search s[k]
void dfs(int k){
    for(int i=0;i<s[k].length();i++){
        if(s[k][i] != '*') ans += s[k][i];
        else if(s[k][i] == '*'){
            int nxt = s[k][++i] - '0';
            if(nxt > n) continue;
            if(!vis[nxt]){
                vis[nxt] = 1;
                dfs(nxt);
                vis[nxt] = 0;
            }else{ // exist loop
                cout << "#";
                exit(0); 
            }
        }
        if(ans.length() > 1000000){
            cout << "#";
            exit(0);
        }
    }
}

void solve(){
    cin>>n;
    for(int i=1;i<=n;i++){
        string str = "", t;
        while(1){
            getline(cin, t); 
            if(str != "") str += '\n';
            str += t;
            if(str.back() == '#') str.pop_back();
            if(t.back() == '#') break;
        }
        s[i] = str; //cerr << s[i] << "\n";
    }
    vis[1] = 1;
    dfs(1);
    vis[1] = 0;
    cout << ans;
    return;
}

signed main(){
    solve();
    return 0;
}
