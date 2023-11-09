#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main(){
    int n; cin>>n;
    for(int a=1;a<=3500;a++){
        for(int b=1;b<=3500;b++){
            int x = a * b * n;
            int y = 4 * a * b - a * n - b * n;
            if(y > 0 && x % y == 0){
                cout << a << " " << b << " " << x / y << "\n";
                return 0;
            }
        }
    }
    return 0;
}

/**
 * 4 / n = 1 / a + 1 / b + 1 / c
 * 4abc = bcn + acn + abn
 * 
 * a b n 为 常量
 * 4ab = bn + an + abn / c  
 * 4ab - an - bn = abn / c
 * c = abn / (4ab - an - bn)
 */
