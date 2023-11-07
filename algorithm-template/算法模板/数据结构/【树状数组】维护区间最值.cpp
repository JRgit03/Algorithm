/**
 * 树状数组维护前缀最大值 + 离散化值域
 * https://leetcode.cn/problems/maximum-balanced-subsequence-sum/
 */

#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10;
int n;
int a[maxn];
int tr[maxn];

int lowbit(int x){
    return x&(-x);
}

// n * logn * logn
int getmax(int l,int r){
    int ans = 0;
    while(l <= r){
        ans = max(ans,a[r]);
        r--;
        for(;r-lowbit(r)>=l;r-=lowbit(r)) 
            ans = max(ans, tr[r]);
    }
    return ans;
}

void update(int x,int v){
    a[x] = v;
    for(int i=x;i<=n;i+=lowbit(i)){
        tr[i] = a[i];
        for(int j=1;j<lowbit(i);j*=2){ //枚举受影响的区间
            tr[i] = max(tr[i],tr[i-j]);
        }
    }
} 

int main(){
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++) update(i,a[i]);
    int q;cin>>q;
    while(q--){
        int l,r; cin>>l>>r;
        cout << getmax(l,r) << "\n";
    }
    return 0;
}