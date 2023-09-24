#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 510;
int a[N][N];
int row[N],col[N];
void solve(){
    int n; cin>>n;
    int ansrow = 0 , anscol = 0;
    memset(row,0x3f,sizeof row);
    memset(col,0x3f,sizeof col);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin>>a[i][j];
            if(a[i][j] <= 0){
                ansrow += a[i][j];
                anscol += a[i][j];
                row[i] = -1;
                col[j] = -1;
            }else{
                row[i] = min(row[i],a[i][j]);
                col[j] = min(col[j],a[i][j]);
            }
        }
    }
    for(int i=1;i<=n;i++){
        if(row[i] > 0){
            ansrow += row[i];
        }
        if(col[i] > 0){
            anscol += col[i];
        }
    }
    cout << min(ansrow,anscol) << "\n";
}

signed main(){
    int t; cin>>t;
    while(t--) solve();
    return 0;
}