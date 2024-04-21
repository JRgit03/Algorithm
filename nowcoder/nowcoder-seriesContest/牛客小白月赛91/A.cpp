#include <bits/stdc++.h>
using namespace std;

string g[10];

void solve(){
    for(int i=0;i<=5;i++) cin>>g[i];
    if(g[5][3] == '|') cout << "p" << "\n";
    else if(g[3][5] != '.') cout << "o" << "\n";
    else cout << "m" << "\n";
}

int main(){
    solve();
    return 0;
}