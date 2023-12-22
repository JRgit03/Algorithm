// 区间选点
// 给定 N 个闭区间 [ai,bi]，请你在数轴上选择尽量少的点，使得每个区间内至少包含一个选出的点。
#include <bits/stdc++.h>
using namespace std;
const int N = 1e3 + 10;
int n,d;

struct Node{
    double l,r;
    bool operator < (const Node &o) const {
        return r < o.r;
    }
}segs[N];

int main(){
    cin>>n>>d;
    bool suc = true;
    for(int i=1;i<=n;i++){
        int x,y; cin>>x>>y;
        if(d < y) suc = false;
        double len = sqrt(d * d - y * y);
        segs[i] = {x-len,x+len};
    }
    sort(segs+1,segs+1+n);
    int ans = 0; double ed = -2e9;
    for(int i=1;i<=n;i++)
        if(segs[i].l > ed){
            ans += 1;
            ed = segs[i].r;
        }
    if(!suc) ans = -1;
    cout << ans << "\n";
    return 0;
}
