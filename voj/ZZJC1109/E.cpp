/**
 * Difficulty: 1158
 * https://atcoder.jp/contests/tenka1-2017-beginner/tasks/tenka1_2017_c
 */
#include <bits/stdc++.h>
using namespace std;

bool check1(int a,int b,int c,int n){
    return 1LL * b * c * n + 1LL * a * c * n + 1LL * a * b * n - 1LL * 4 * a * b * c >= 0;
}

bool check2(int a,int b,int c,int n){
    return 1LL * b * c * n + 1LL * a * c * n + 1LL * a * b * n - 1LL * 4 * a * b * c == 0;
}

// 从时间复杂度入手题目
// f(c) = 1 / c + 1 / a + 1 / b - 4 / n 
// 二分时间复杂度 O(n^2logn) n = 3500 题目保证有解 144220955 1e8 
 
int main(){
    int n; cin>>n;
    for(int a=1;a<=3500;a++){
        for(int b=1;b<=3500;b++){
            int l = 1, r = 3500;
            while(l < r){
                int mid = l + r + 1 >> 1;
                if(check1(a,b,mid,n)) l = mid;
                else r = mid - 1;
            }
            if(check2(a,b,r,n)) {
                cout << a << " " << b << " " << r << "\n";
                return 0;
            }
        }
    }
    return 0;
}