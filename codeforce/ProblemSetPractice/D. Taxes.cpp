#include <bits/stdc++.h>
using namespace std;

int check(int x){
    for(int i=2;i<=sqrt(x);i++)
        if(x % i == 0) return false;
    return true;
}

int main(){
    int x; cin>>x;
    int ans = -1;
    if(check(x)) ans = 1;
    else if((x + 1) & 1) ans = 2;
    else if(check(x - 2)) ans = 2;
    else ans = 3;
    cout << ans << "\n";
    return 0;
}
