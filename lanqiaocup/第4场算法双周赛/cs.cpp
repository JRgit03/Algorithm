#include <bits/stdc++.h>
using namespace std;

int main(){
    long long mul = 1, cnt = 0;
    while(mul <= 1e12) mul = mul * 2, cnt += 1;
    cout << cnt << "\n";
    return 0;
}
