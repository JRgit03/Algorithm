#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e5 + 10, mod = 99999997;
int n;
struct Node{
    int x,id;
    bool operator < (const Node& o) const {
        return x < o.x;
    };
}a[N], b[N];

int c[N]; // c[i]=j  c下标表示a数组的下标 c数值表示b数组的下标
int tr[N];

int lowbit(int x) {
    return x & -x;
}

void add(int x,int v){
    for(int i=x;i<=n;i+=lowbit(i)) tr[i] += v;
}

int sum(int x){
    int res = 0;
    for(int i=x;i>0;i-=lowbit(i)) res += tr[i];
    return res;
}

// 结论：使得数组有序每次操作为相邻项交换，最小交换次数 等于 原数组逆序对数量
void solve(){
    cin>>n;
    for(int i=1;i<=n;i++){
        int x; cin>>x;
        a[i] = {x, i};
    }    
    for(int i=1;i<=n;i++){
        int x; cin>>x;
        b[i] = {x, i};
    }
    sort(a+1,a+1+n);
    sort(b+1,b+1+n);
    // c数组 第i小的a数组下标与第i小的b数组下标对应
    // 求b数组有序的最小交换次数
    // 最终想让 c[i] = i
    for(int i=1;i<=n;i++) c[a[i].id] = b[i].id;
    // 使得c数组有序 求逆序对数量
    int res = 0;
    for(int i=n;i>0;i--){
        res += sum(c[i]);
        add(c[i], 1);
    }
    cout << (res % mod) << "\n";
}

signed main(){
    solve();
    return 0;
}
