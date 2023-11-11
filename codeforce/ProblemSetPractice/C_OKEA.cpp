#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n,k; cin>>n>>k;
    if(k == 1){
        cout << "YES" << "\n";
        for(int i=1;i<=n;i++) cout << i << "\n";
    }else{
        if(!(n & 1)){
            cout << "YES" << "\n";
            vector<int> vec[n+1]; int t = 0;
            for(int i=1;i<=k;i++){
                for(int j=1;j<=n;j++){
                    vec[j].push_back(++t);
                }
            }
            for(int i=1;i<=n;i++){
                for(int j=1;j<=k;j++){
                    cout << vec[i][j-1] << " ";
                }
                cout << "\n";
            }
        }else{
            cout << "NO" << "\n";
        }
    }
}

int main(){
    int t; cin>>t;
    while(t--)
        solve();
    return 0;
}
