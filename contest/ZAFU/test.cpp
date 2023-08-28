#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;

int calc(int n,int r){ // n的r进制表示
    int res = 0;
    while(n){
        res += n%r;
        n /= r;
    }
    return res;
}

int main(){
    IOS;
    cout << log2(1e18) << "\n";
    return 0;
}
