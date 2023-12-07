#include <bits/stdc++.h>
using namespace std;

int main(){
    int t; cin>>t;
    for(int T=1;T<=t;T++){
        int n; scanf("%d",&n);
        int ans = 0;
        for(int i=0;i<n;i++){
            int r; scanf("%d",&r);
            ans ^= max(0,r-2);
        }
        printf("Case %d: %d\n",T,ans);
    }
    return 0;
}

// 数学不等式推结论

// k <= j < i    =>   k <= j <= i - 1
// k >= i - r[i] + 1 >= 1
// k >= j - r[j] + 1 >= 1
// i <= j + r[j] - 1
// i - r[i] + 1 <= i+1 + r[i+1] + 1
// j - k >= i - j >= 1

// k属于[i-r[i]+1,i-2]