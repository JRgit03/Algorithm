#include <bits/stdc++.h>
#define int long long
using namespace std;
const int maxn = 1e5 + 10;
int n;
int a[maxn],b[maxn];

signed main(){
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++) b[i] = a[i] - a[i-1];
    int c = 0,d = 0;
    for(int i=2;i<=n;i++) 
        if(b[i] > 0) c += b[i];
        else d += -b[i];
    cout << min(c,d) + abs(c-d) << "\n";
    cout << abs(c-d) << "\n";    
    return 0;
}

// a:4 1 1 2 2
// b:4 -3 0 1 0

// 操作等价于 
// 在差分数组中 选择一个i,j(i<j) b[i] += 1, b[j] -= 1 / b[i] -= 1. b[j] += 1
// 终止使得 b[2~n] = 0

// 1. 1<i<j i j 一正一负 尽可能处理这种
// 2. i = 1, j  
// 3. i > 1, j = n+1
// 4.