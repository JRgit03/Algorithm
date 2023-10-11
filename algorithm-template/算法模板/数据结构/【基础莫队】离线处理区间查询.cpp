/**
 * O(n * sqrt(n) + m * sqrt(n))
 * 普通莫队 = 分块 + 排序暴力 
 */
#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
using namespace std;
typedef long long ll;
const int N = 1e5 + 10;
int n,m,k;
int res,ans[N];
int a[N];

// 分块部分 block代表每块大小 pos[i]代表位置i的块编号
int block,pos[N];
struct Q{
    int l,r,k;
    bool operator < (const Q & t) const {
        if(pos[l] != pos[t.l]) return pos[l] < pos[t.l]; // 左端点所在块
        return r < t.r; // 右端点
    }
}q[N];

// 添加第x位对答案的贡献
void add(int x){
    
}

// 删除第x位对答案的贡献
void sub(int x){
    
}

int main(){
    IOS;
    cin>>n>>m>>k;
    // 分块操作
    block = sqrt(n);
    for(int i=1;i<=n;i++){
        pos[i] = (i - 1) / block + 1;
    }
    // 初始化
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=0;i<m;i++){
        cin>>q[i].l>>q[i].r;
        q[i].k = i;
    }
    // 处理查询
    sort(q,q+m);
    int l=1,r=0; // 初始区间不合法
    for(int i=0;i<m;i++){ //暴力移动 l,r
        while(l < q[i].l) sub(l++);
        while(l > q[i].l) add(--l);
        while(r < q[i].r) add(++r);
        while(r > q[i].r) sub(r--);
        ans[q[i].k] = res;
    }
    for(int i=0;i<m;i++){ //按照询问顺序输出ans
        cout << ans[i] << "\n";
    }
    return 0;
}
