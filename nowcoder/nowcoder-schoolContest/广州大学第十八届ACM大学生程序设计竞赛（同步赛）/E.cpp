#include <bits/stdc++.h>
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4.1,sse4.2,avx,avx2,popcnt,tune=native")
using namespace std;

template <typename T>
inline void read(T &f)
{
    f=1;
    T x=0;
    char ch=getchar();
    while(ch<'0'||ch>'9')
    {
        if(ch=='-')
            f=-1;
        ch=getchar();
    }
    while(ch>='0'&&ch<='9')
    {
        x=x*10+ch-'0';
        ch=getchar();
    }
    f*=x;
}
template <typename T>
inline void print(T x)
{
    if(x<0)
    {
        putchar('-');
        x=-x;
    }
    if(x>9)
        print(x/10);
    putchar(x%10+'0');
}

const int N = 2e6 + 10;
int n;
int col[N];

int tr[N];
int lowbit(int x){return x&-x;}
void add(int x,int c){for(int i=x;i<=n&&i>0;i+=lowbit(i)) tr[i] += c;}
int sum(int x){int res = 0;for(int i=x;i>0;i-=lowbit(i)) res += tr[i];return res;}

vector<int> g[N];
int din[N],dout[N],tot;
int mp[N]; // mp[i] dfn为i的点为mp[i]
void dfs(int u){
    din[u] = ++tot;
    mp[tot] = u; 
    for(auto &v : g[u])
        dfs(v);
    dout[u] = tot; 
}

int last[N]; // last[i] 颜色为i的上一个位置
struct Q{
    int l,r,id;
    bool operator < (const Q& o) const {
        return r < o.r;
    }
}q[N];

int main(){
    read(n);
    for(int i=1;i<=n;i++) read(col[i]);
    for(int i=1,u,v;i<=n-1;i++){
        read(u); v = i+1;
        g[u].emplace_back(v);
    }
    dfs(1);
    for(int i=1;i<=n;i++) q[i] = {din[i],dout[i],i};
    sort(q+1, q+1+n);
    int t = 1,ans = 0;
    for(int i=1;i<=n;i++){
        add(last[col[mp[i]]], -1);
        add(i, 1);
        last[col[mp[i]]] = i;
        while(q[t].r == i && t <= n){
            if(sum(q[t].r) - sum(q[t].l - 1) == q[t].r - q[t].l + 1) ans += 1;
            t += 1;
        }
    }
    print(ans);
    return 0;
}
