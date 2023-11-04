// 预处理出每一行的可能的所有状态
// O(60^5 * n^2)
#include <bits/stdc++.h>
using namespace std;
int n;
int ok;
string R,C;
vector<string> g(10);
vector<string> all;

char Top[10];
int col[10][3];

bool check(){
    for(int i=1;i<=n;i++) Top[i] = '.';
    memset(col,0,sizeof col);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(g[i][j-1] != '.') col[j][g[i][j-1]-'A']++;
            if(Top[j] == '.'){
                Top[j] = g[i][j-1];
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=0;j<=2;j++){
            if(col[i][j] != 1){
                return false;
            }
        }
    }
    for(int i=1;i<=n;i++) 
        if(Top[i] != C[i]) 
            return false;
    return true;
}

// 当前处理第k行
void dfs(int k){
    if(ok == 1) return;
    if(k == n+1){
        if(!check()) return;
        ok = 1;
        cout << "Yes" << "\n";
        for(int i=1;i<=n;i++) cout << g[i] << "\n";
        return;
    }
    // 枚举当前的方案
    for(auto cur : all){
        int t = 0; while(cur[t] == '.') t++;
        if(cur[t] != R[k]) continue;
        g[k] = cur;
        dfs(k+1);
    }
}

int main(){
    cin>>n>>R>>C; R = "?" + R; C = "?" + C;
    string s = "ABC";
    for(int i=0;i<n-3;i++) s += '.';
    sort(s.begin(),s.end());
    do{all.push_back(s);}while(next_permutation(s.begin(),s.end()));
    // cout << all.size() << "\n";
    // for(auto s : all) cout << s << "\n";
    dfs(1);
    if(!ok) cout << "No" << "\n";
    return 0;
}
