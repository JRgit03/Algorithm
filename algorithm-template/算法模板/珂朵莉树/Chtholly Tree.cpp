// ODT树是一种数据随机的区间操作算法，可以用STL的set实现，提高骗分效率
// 珂朵莉树适用范围：区间赋值操作!且数据随机 
// https://zhuanlan.zhihu.com/p/106353082
// https://www.bilibili.com/video/BV1QW411T7nz/?vd_source=632b900659c1954e964a52b4d43dc39b

// practice 
// https://leetcode.cn/problems/count-integers-in-intervals/description/?envType=daily-question&envId=2023-12-16
// https://codeforces.com/problemset/problem/896/C
// https://codeforces.com/contest/915/problem/E

// 注意初始化问题 根据题意
// 常见初始化 
// tree.insert(node(i, i, a[i]));  i 1~n
// tree.insert(node(1,n,0)) 
// tree.insert(node(1,n,1))
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct node{
    ll l,r;
    mutable ll v;
    node(ll l,ll r,ll v): l(l), r(r), v(v) {} // 构造函数
    bool operator < (const node& o) const {return l < o.l;} // 重载小于运算符
};

set<node> tree;

#define iter set<node>::iterator 

// 返回区间{pos,r,v}的迭代器
// {l,r,v} -> {l,pos-1,v} + {pos,r,v}
iter split(ll pos){
    iter it = tree.lower_bound(node(pos,0,0)); // 寻找左端点 >= pos 的 第一个节点
    if(it != tree.end() && it->l == pos) return it;
    it--; // 否则往前数一个节点
    ll l = it->l, r = it->r, v = it->v;
    tree.erase(it); // 删除该节点
    tree.insert(node(l, pos - 1, v)); // 插入<l,pos-1,v>和<pos,r,v>
    return tree.insert(node(pos, r, v)).first; // 返回以pos开头的那个节点的迭代器
}

// 区间推平 区间赋上相同的值
void assign(ll l, ll r, ll v){
    iter end = split(r + 1), begin = split(l); // 顺序不能颠倒，否则可能RE
    tree.erase(begin, end); // 清除一系列节点 st.erase(st,ed)
    tree.insert(node(l, r, v)); // 插入新的节点
}

// 接下来的 Brute force 计算
// 区间加
void add(ll l, ll r, ll v){
    iter end = split(r + 1), begin = split(l); 
    for(iter it = begin ;it != end; it++){
        it->v += v;   
    }
}

// 区间第k大
ll kth(ll l,ll r, ll k){
    iter end = split(r + 1), begin = split(l); 
    vector<pair<ll,ll>> vec; // {区间值, 区间长度}...
    for(iter it = begin; it != end; it++)
        vec.push_back({it->v,it->r-it->l+1});
    sort(vec.begin(),vec.end());
    for(int i=0;i<vec.size();i++){
        k -= vec[i].second;
        if(k <= 0) return vec[i].first;
    }
    return -1;
}

ll range_sum(ll l,ll r){
    iter end = split(r + 1), begin = split(l); 
    ll res = 0;
    for(iter it = begin; it != end; it++){
        res += (it->r-it->l+1) * it->v;
    }
}

ll fastpow(ll a,ll b,ll p){
    ll res = 1;
    while(b){
        if(b & 1) res = res * a % p;
        b >>= 1;
        a = a * a % p;
    }
    return res % p;
}

// sum(l~r) a[i]^x % y
ll sum_pow(ll l, ll r,ll x, ll y){
    iter end = split(r + 1), begin = split(l);
    ll ans = 0;
    for(iter it = begin; it != end; it++)
        ans = (ans + (it->r-it->l+1) % y * fastpow((it->v)%y,x,y) % y) % y;
    return ans;
}

