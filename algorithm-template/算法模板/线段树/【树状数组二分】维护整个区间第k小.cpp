#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 10;
int n,q;
int a[maxn];
int tr[maxn];

int lowbit(int x){
    return x & -x;
}

void add(int k,int val){
    for(int i=k;i<=1000000;i+=lowbit(i)) tr[i] += val; 
}

// 返回 1~x 之和 前缀和
int query(int x){
    int res = 0;
    for(int i=x;i;i-=lowbit(i)) res += tr[i];
    return res;
}

int kth(int k){
    int l = 1, r = 1000000; 
    while(l < r){
        int mid = l + r >> 1;
        int cnt = query(mid) - query(l-1);
        if(cnt >= k) r = mid;
        else l = mid + 1, k -= cnt;
    }
    return r;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>n>>q;
    for(int i=1;i<=n;i++) {
        cin>>a[i]; add(a[i],1);
    }
    while(q--){
        int op,x,y; cin>>op;
        if(op == 1) {
            cin>>x;
            cout << kth(x) << "\n";
        }else{
            cin>>x>>y;
            add(a[x],-1);
            a[x] = y;
            add(a[x],1);
        }
    }
    return 0;
}

// 与权值线段树类似 
// 维护桶 每个数值出现的个数
// 对树状数组二分