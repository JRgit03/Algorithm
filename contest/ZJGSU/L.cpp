#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;

int main(){
    IOS;
    int t;cin>>t;while(t--){
        int n,m,k;cin>>n>>m>>k;
        cout << (n-m + k-1)/k + 1 << "\n";
    }
    return 0;
}
