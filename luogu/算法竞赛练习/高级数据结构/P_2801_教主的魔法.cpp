#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
using namespace std;
const int N = 1e6 + 10 , M = 1e3 + 10;
int n,q;
int a[N],b[N];

int t,block; // t 分块个数 block分块大小
int pos[N]; // pos[i] 代表 i 在 拿个分块
int st[M],ed[M]; // st[i],ed[i] 代表 第i个分块的起始位置和终止位置
int add[M],sum[M];

// 建立分块 + init
void build(){
    block = sqrt(n);
    t = n / block;
    if(n % block) t++;
    for(int i=1;i<=t;i++) {
        st[i] = (i-1) * block + 1;
        ed[i] = i * block;
    }
    ed[t] = n;
    for(int i=1;i<=n;i++){
    	b[i] = a[i];
        pos[i] = (i - 1) / block + 1;
    }

    for(int i=1;i<=t;i++) {
        sort(b+st[i],b+ed[i]+1);
    }
}

// 重设第k个分块
void reset(int k){
    for(int i=st[k];i<=ed[k];i++) b[i] = a[i];
    sort(b+st[k],b+ed[k]+1);
}

void upd(int L,int R,int c){
    int p = pos[L] , q = pos[R];
    if(p == q){
        for(int i=L;i<=R;i++) a[i] += c;
        reset(p);
    }else{
        for(int i=p+1;i<=q-1;i++) add[i] += c;
        for(int i=L;i<=ed[p];i++) a[i] += c;
        reset(p);
        for(int i=st[q];i<=R;i++) a[i] += c;
        reset(q);
    }
}

int ask(int L,int R,int c){
    int p = pos[L] , q = pos[R];
    int ans = 0;
    if(p == q){
        for(int i=L;i<=R;i++) ans += (a[i] + add[p] >= c);
    }else{
        for(int i=p+1;i<=q-1;i++){
            ans += (b[ed[i]] < c - add[i] ? 0 : (b+ed[i]) - lower_bound(b+st[i],b+ed[i]+1,c-add[i]) + 1);
        }

        for(int i=L;i<=ed[p];i++) ans += (a[i] + add[p] >= c);
        for(int i=st[q];i<=R;i++) ans += (a[i] + add[q] >= c);
    }
    return ans;
}

void solve(){
    cin>>n>>q;
    for(int i=1;i<=n;i++) cin>>a[i];
    build();
    for(int i=0;i<q;i++){
        char op; int a,b,c; cin>>op>>a>>b>>c;
        if(op == 'A') cout << ask(a,b,c) << "\n";
        else upd(a,b,c);
    }
}

int main(){
    IOS; solve();
    return 0;
}
