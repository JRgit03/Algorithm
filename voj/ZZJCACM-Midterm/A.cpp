#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,x;cin>>n>>x;
    int res = 0;
    for(int i=1;i<=n;i++){
        int cur = i;
        while(cur) res += (cur%10==x) , cur /= 10;
    }
    cout << res << "\n";
    return 0;
}
