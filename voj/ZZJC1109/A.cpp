/**
 * Difficulty: 337
 * https://atcoder.jp/contests/abc079/tasks/abc079_c
 * 
 * 题意：询问是否存在一个运算符(+,-)组合使得等式成立 
*/
#include <bits/stdc++.h>
using namespace std;


// 显然 8个if能够搞定
// 思考：如果给你n+1个数n个运算符 for/暴力写出所有(1<<n)种可能 是不是太麻烦? 爆搜也ok

int main(){
    string s; cin>>s;
    vector<int> a(4); for(int i=0;i<4;i++) a[i] = s[i] - '0';
    for(int i=0;i<(1<<3);i++){ // 0 -> 减      1 -> 加  二进制枚举
        int val = a[0];
        vector<char> op;
        for(int j=0;j<3;j++){
            int x = (i >> j) & 1;
            if(x == 0) op.push_back('-'), val -= a[j+1];
            else op.push_back('+'), val += a[j+1];
        }
        if(val == 7){
            printf("%d%c%d%c%d%c%d=7\n",a[0],op[0],a[1],op[1],a[2],op[2],a[3]);
            return 0;
        }
    }
    return 0;
}

// +/- 一共就两个状态
// 二进制枚举 一个数代表一种选法 

// 5 = 101 +-+
// (i >> j) & 1 => i的第j位的值

// 常见位运算技巧
// https://leetcode.cn/circle/discuss/CaOJ45/
