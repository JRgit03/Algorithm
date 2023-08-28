#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;cin>>n;
    int cnt = 0;
    while(n) {
        if(n&1)cnt++;
        n >>= 1;
    }
    cout << cnt << "\n";
    return 0;
}
