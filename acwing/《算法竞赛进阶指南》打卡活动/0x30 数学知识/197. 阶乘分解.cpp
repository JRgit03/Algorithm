#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 10;
int n;
int primes[maxn],cnt;
int st[maxn];

int main(){
    cin>>n;
    for(int i=2;i<=n;i++){
        if(!st[i]) primes[cnt++] = i;
        for(int j=0;primes[j]<=n/i;j++){
            st[primes[j]*i] = 1;
            if(i % primes[j] == 0) break;
        }
    }
    // 计算 n!中质因子p的出现次数
    auto calc = [&](int n,int p){ 
        int s = 0;
        for(;n/p>0;n/=p) s += n/p;
        return s;
    };
    for(int i=0;i<cnt;i++)
        printf("%d %d\n",primes[i],calc(n,primes[i]));
    return 0;
}

// 5! = 1 * 2 * 3 * 4 * 5