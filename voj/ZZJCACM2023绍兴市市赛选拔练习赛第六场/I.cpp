#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n; cin>>n;
    if(n == 2){
        cout << "0 2 1 3" << "\n";
        return;
    }
    for(int i=0;i<n-1;i++) 
        cout << i << " " << i + n << " ";
    cout << n - 1 << " " << 3 * n - 4 << "\n";
}

int main(){
    int t; cin>>t;
    while(t--)  
        solve();
    return 0;
}
