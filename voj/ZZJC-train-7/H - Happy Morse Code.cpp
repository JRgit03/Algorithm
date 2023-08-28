#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int son[N][26],cnt[N],idx;

void insert(char *str){
    int p = 0;
    for(int i=0;str[i];i++){
        int u = str[i] - 'a';
        if(!son[p][u]) son[p][u] = ++idx;
        p = son[p][u];
    }
    cnt[p]++;
} 

int query(char *str){
    int p = 0;
    for(int i=0;str[i];i++){
        int u = str[i] - 'a';
        if(!son[p][u]) return 0;
        p = son[p][u];
    }
    return cnt[p];
}

void solve(){
    int n,m;cin>>n>>m;
    for(int i=1;i<=n;i++){
        char c;char str[10];
        cin>>c>>str;
        insert(str);
        
    }
    char str[10]; cin>>str;
    cout << query(str) << "\n";
}

int main(){
    int t;cin>>t;
    while(t--)solve();
    return 0;
}
