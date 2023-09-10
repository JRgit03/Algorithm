#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
using namespace std;

void solve(){
    int n;cin>>n;
    if(n & 1){
        cout << 1 + n / 2 / 3 + n / 2 / 3 << " ";
    }else{
        cout << 2 + (n / 2 - 1) / 3 * 2 << " ";
    }
    cout << n << "\n";
}

int main(){
    IOS; solve();
    return 0;
}
