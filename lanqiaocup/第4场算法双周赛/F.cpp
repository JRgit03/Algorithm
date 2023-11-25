#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
#define dbug(x) cout << #x << '=' << x << endl
#define x first
#define y second
using namespace std;
const int N = 1e5 + 10, Mod = 1e9 + 7, INF = 0x3f3f3f3f;
const double PI = acos(-1.0);
typedef pair<int,int> PII;
typedef long long ll;
const int maxn = 2e5 + 10;

int n,q;
int a[maxn];
vector<int> b;

struct Node{
    int l,r;
    int sum;
}tr[maxn<<4];

void pushup(int u){
    tr[u].sum = tr[u<<1].sum + tr[u<<1|1].sum;
}

void build(int u,int l,int r){
    if(l == r) tr[u] = {l,r,0};
    else {
        tr[u] = {l,r,0};
        int mid = l + r >> 1;
        build(u<<1,l,mid);
        build(u<<1|1,mid+1,r);
    }
}

void modify(int u,int pos,int val){
    if(tr[u].l == tr[u].r) tr[u].sum += val;
    else{
        int mid = tr[u].l + tr[u].r >> 1;
        if(pos <= mid) modify(u<<1,pos,val);
        else modify(u<<1|1,pos,val);
        pushup(u);
    }
}

int kth(int u,int k){
    if(tr[u].l == tr[u].r) return tr[u].r;
    else{
        if(k <= tr[u<<1].sum) return kth(u<<1,k);
        return kth(u<<1|1,k-tr[u<<1].sum);
    }
}

int find(int x){
    return lower_bound(b.begin(),b.end(),x) - b.begin() + 1;
}

void solve(){
    build(1,1,200010);
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        b.push_back(a[i]);
    } 
    sort(b.begin(),b.end());
    b.erase(unique(b.begin(),b.end()),b.end());
    for(int i=1;i<=n;i++) modify(1,find(a[i]),1);
    scanf("%d",&q);
    while(q--){
        int x; scanf("%d",&x); n--;
        modify(1,find(a[x]),-1); 
        if(n % 2 == 1){
            // cout << b[kth(1,n/2+1)-1] << "\n";
            printf("%.1lf ",b[kth(1,n/2+1)-1]*1.0);
        }else{
            int l = n / 2, r = l + 1;
            // cout << b[kth(1,l)-1] << " " <<  b[kth(1,r)-1] << "\n";
            printf("%.1lf ",(b[kth(1,l)-1] + b[kth(1,r)-1]) * 1.0 / 2.0);
        }
    }
}

signed main(){
    solve();
    return 0;
}
