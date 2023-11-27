// https://ac.nowcoder.com/acm/contest/69246/P

#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e3 + 10;
int n,m;
int a[maxn];
bitset<maxn*maxn> dp[maxn]; // dp[i][j]表示体积恰好为i价值为j的是否存在

int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    dp[0].set(0,1);  // eg: 00000000 -> 00000001 bs.set(x) 将x位置为1(从0位开始)
    for(int i=1;i<=n;i++) // O(n*m*(1e6/32)) 超时...
        for(int j=1;j<=m;j++)
            dp[j] |= dp[j-1] << a[i];
    for(int i=1;i<=1000000;i++)
        if(dp[m][i])
            printf("%d ",i);
    return 0;
}

/**
bitset支持 & | ^ << >>  
foo.size() 返回大小（位数）
foo.count() 返回1的个数
foo.any() 返回是否有1
foo.none() 返回是否没有1
foo.set() 全都变成1
foo.set(p) 将第p + 1位变成1
foo.set(p, x) 将第p + 1位变成x
foo.reset() 全都变成0
foo.reset(p) 将第p + 1位变成0
foo.flip() 全都取反
foo.flip(p) 将第p + 1位取反
foo.to_ulong() 返回它转换为unsigned long的结果，如果超出范围则报错
foo.to_ullong() 返回它转换为unsigned long long的结果，如果超出范围则报错
foo.to_string() 返回它转换为string的结果
 * */ 