#include <bits/stdc++.h>
using namespace std;

// p-6 p p+6

// 12: 1 12 -- 2 6 3 4

// 结论一： 一个数x为合数 则 必定在 2~sqrt(x) 存在合数因子
bool check(int x){ // O(sqrt(n))
    if(x < 2) return false;
    for(int i=2;i<=x/i;i++)
        if(x % i == 0) 
            return false;
    return true;
}

int main(){
    int n; cin>>n;
    if(check(n) && check(n-6)){
        cout << "Yes" << "\n" << n - 6 << "\n";
    }else if(check(n) && check(n+6)){
        cout << "Yes" << "\n" << n + 6 << "\n";
    }else{
        // 结论二： 众所周知两个相邻的质数不会相差很远 => 下一个性感素数不会相差很远
        while(++n){
            if((check(n) && check(n-6)) || (check(n) && check(n+6))){
                cout << "No" << "\n" << n << "\n";
                return 0; 
            }
        }
    }
    return 0;
}
