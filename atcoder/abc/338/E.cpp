// #### 问题陈述
// 在一个圆上有$2N$个等间隔的点，从某点开始按顺时针方向依次编号为$1$至$2N$。
// 圆上还有 $N$ 条弦，其中 $i$ 条弦连接点 $A_i$ 和 $B_i$。保证所有的值 $A_1,\dots,A_N,B_1,\dots,B_N$ 都是不同的。
// 判断这些弦之间是否有交点。

#include <bits/stdc++.h>
using namespace std;

struct Seg{
    int l,r;
    bool operator < (const Seg &o) const {
        return l < o.l;
    }
};

// 方法 弦是否有交点 <=> 是否存在区间是否相交 <=> 括号匹配问题
int main(){
    int n; cin>>n;
    vector<Seg> vec(n);
    for(int i=0;i<n;i++){
        int l,r; cin>>l>>r;
        if(l > r) swap(l,r);
        vec[i] = {l,r};
    }
    sort(vec.begin(), vec.end());
    set<int> st; // 按左端点排序后 用set维护有序的右端点集合
    for(int i=0;i<n;i++){
        auto [l,r] = vec[i];
        auto it = st.upper_bound(l);
        if(it == st.end()){
            st.insert(r);
            continue;
        }
        if(*it < r){
            cout << "Yes" << "\n";
            return 0;
        }
        st.insert(r);
    }
    cout << "No" << "\n";
    return 0;
}
