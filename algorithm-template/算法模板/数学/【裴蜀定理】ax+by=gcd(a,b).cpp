/**
 * https://www.luogu.com.cn/record/123250878
 * 
 * 裴蜀定理(或贝祖定理)说明了对任何整数a、b和它们的最大公约数d，
 * 关于未知数x和y的线性不定方程(称为裴蜀等式)：若a,b是整数,且gcd(a,b)=d，
 * 那么对于任意的整数x,y,ax+by都一定是d的倍数，特别地，
 * 一定存在整数x,y，使ax+by=d成立。
 * 它的一个重要推论是：a,b互质的充要条件是存在整数x,y使ax+by=1.
 * gcd(a,b) = gcd(b,a-b);
 */
#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
using namespace std;

int gcd(int a, int b){
    return b ? gcd(b, a % b) : a;
}

int main(){
    IOS;
    int n;cin>>n;
    int ans = 0;
    for(int i=0;i<n;i++){
        int x;cin>>x; if(x<0) x=-x;
        ans = gcd(ans,x);
    }
    cout << ans << "\n";
    return 0;
}
