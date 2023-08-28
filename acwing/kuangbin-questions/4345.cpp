#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
using namespace std;
const int N = 5e4 + 10;
int n,m;

struct Node{
    int l,r;
    int val,pre,suf; // 区间内连续1的最大长度,pre最大前缀,suf最大后缀
}tr[N*4];

void pushup(int u){
    auto &root = tr[u] , &left = tr[u<<1] , &right =  tr[u<<1|1];
    root.val = max(left.val,right.val);
    root.val = max(root.val,left.suf+right.pre);
    root.pre = left.pre , root.suf = right.suf;
    if(left.val == left.r - left.l + 1) root.pre += right.pre;
    if(right.val == right.r - right.l + 1) root.suf += left.suf;   
}

void build(int u,int l,int r){
    if(l==r) tr[u] = {l,r,1,1,1};
    else{
        tr[u] = {l,r};
        int mid = l+r >> 1;
        build(u<<1,l,mid) , build(u<<1|1,mid+1,r);
        pushup(u);
    }
}

void modify(int u,int k,int d){
    if(tr[u].l==tr[u].r&&tr[u].l==k) tr[u].val = tr[u].pre = tr[u].suf = d;
    else{
        int mid = tr[u].l + tr[u].r >> 1;
        if(k<=mid) modify(u<<1,k,d);
        else modify(u<<1|1,k,d);
        pushup(u);
    }
}

int query(int u,int k){
    if(tr[u].l==tr[u].r || !tr[u].val || tr[u].val == tr[u].r - tr[u].l + 1) return tr[u].val;
    else{
        int mid = tr[u].l + tr[u].r >> 1;
        if(k>=mid-tr[u<<1].suf+1&&k<=mid+tr[u<<1|1].pre) return tr[u<<1].suf + tr[u<<1|1].pre;
        if(k<=mid) return query(u<<1,k);
        else return query(u<<1|1,k);
    }
}

int main(){
    IOS;
    while(cin>>n>>m){
        build(1,1,n);
        stack<int> stk;
        while(m--){
            char op;cin>>op;
            if(op=='D'){
                int k;cin>>k;modify(1,k,0);
                stk.push(k);
            }else if(op=='Q'){
                int k;cin>>k;cout<<query(1,k)<<"\n";
            }else{
                if(stk.size()) modify(1,stk.top(),1) , stk.pop();
            }
        }
    }    
    return 0;
}
