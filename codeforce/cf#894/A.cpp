#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;

void solve(){
	string tar = "vika"; int cur = 0;
    int n,m;cin>>n>>m;
    char g[n][m];
    for(int i=0;i<n;i++) 
        for(int j=0;j<m;j++)
            cin>>g[i][j];
    for(int i=0;i<m;i++){
        bool f = false;
        for(int j=0;j<n;j++)
            if(g[j][i] == tar[cur])
                f = true;
        cur += f;
        if(cur == 4) {
            cout << "YES" << "\n";
            return;
        }
    }
    cout << "NO" << "\n";
    return;    
}

int main(){
	IOS;
	int t;cin>>t;while(t--)solve();
	return 0;
}