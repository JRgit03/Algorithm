#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 5e4 + 10;
int n,m;
int pos[N],block;
pair<int,int> ans[N];
int res; 
int c[N],cnt[N];

struct Q{
    int l,r,k;
    bool operator < (const Q& t) const {
        if(pos[l] != pos[t.l]) return pos[l] < pos[t.l];
        return r < t.r;
    };
}q[N];

void add(int x){
    res -= 1LL * cnt[c[x]] * (cnt[c[x]] - 1) / 2;
    cnt[c[x]] ++;
    res += 1LL * cnt[c[x]]  * (cnt[c[x]] - 1) / 2; 
}

void sub(int x){
    res -= 1LL * cnt[c[x]] * (cnt[c[x]] - 1) / 2;
    cnt[c[x]] --;
    res += 1LL * cnt[c[x]]  * (cnt[c[x]] - 1) / 2; 
}

int main(){
    scanf("%d%d",&n,&m);
    block = sqrt(n);
    for(int i=1;i<=n;i++) pos[i] = (i-1)/block + 1;
    for(int i=1;i<=n;i++) scanf("%d",&c[i]);
    for(int i=0;i<m;i++){
        scanf("%d%d",&q[i].l,&q[i].r);
        q[i].k = i;
    }
    sort(q,q+m);
    int l = 1, r = 0;
    for(int i=0;i<m;i++){
        while(l > q[i].l) add(--l);
        while(r < q[i].r) add(++r);
        while(l < q[i].l) sub(l++);
        while(r > q[i].r) sub(r--);
        ans[q[i].k] = {res,1LL*(q[i].r-q[i].l+1)*(q[i].r-q[i].l)/2};
    }
    for(int i=0;i<m;i++) {
        auto [a,b] = ans[i];
        if(!a || !b) printf("0/1\n");
        else {
            int x = __gcd(a,b);
            a /= x , b /= x;
            printf("%d/%d\n",a,b);
        }
    }
    return 0;
}
