#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
using namespace std;
typedef long long ll;
const int N = 1e5 + 10;
int n,m;
int now; //区间数值种类个数
int a[N],cnt[N];
int ans[N];

int block,pos[N];
struct Q{
    int l,r,k;

    bool operator < (const Q &t) const {
        if(pos[l] != pos[t.l]) return pos[l] < pos[t.l];
        return r < t.r;
    }
}q[N];

void add(int x){
    cnt[a[x]]++;
    if(cnt[a[x]] == 1) now++;
}

void sub(int x){
    cnt[a[x]]--;
    if(cnt[a[x]] == 0) now--;
}

int main(){
    IOS;
    cin>>n>>m;
    block = sqrt(n);
    for(int i=1;i<=n;i++) {
        pos[i] = (i-1) / block + 1;
    }
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=0;i<m;i++){
        cin>>q[i].l>>q[i].r;
        q[i].k = i;
    }
    sort(q,q+m);
    int l=1,r=0; 
    for(int i=0;i<m;i++){
        while(l > q[i].l) add(--l);
        while(r < q[i].r) add(++r);
        while(l < q[i].l) sub(l++);
        while(r > q[i].r) sub(r--);
        ans[q[i].k] = (now == (q[i].r - q[i].l + 1));
    }
    for(int i=0;i<m;i++){
        cout << (ans[i] ? "Yes" : "No") << "\n";
    }
    return 0;
}
