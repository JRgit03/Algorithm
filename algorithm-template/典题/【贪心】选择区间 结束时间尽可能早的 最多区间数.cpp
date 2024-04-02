/*
    题意: 给定n个区间,ai开始时间,bi结束时间
          存在k个容纳区间的队列... 假如aj>=bi表明第j个区间可以紧跟着第i个即不冲突
          问 在区间不冲突的前提下 k个队列最大可以存储的区间数
    题解：贪心 + multiset 优先按照区间右端点排序升序,再按区间左端点排降序
*/
void solve(){
    int n,k; cin>>n>>k;
    multiset<int> st; //注意得开multiset
    vector<array<int,2>> seg(n);
    for(int i=0;i<n;i++){
        cin>>seg[i][0]>>seg[i][1];
    }
    sort(seg.begin(), seg.end(), [&](auto &p, auto &q){
        return p[1] != q[1] ? p[1] < q[1] : p[0] > q[0];
    });
    int ans = 0;
    for(int i=0;i<n;i++){
        if(st.size() == 0){
            st.insert(seg[i][1]);
            ans += 1;
        }else{ 
            auto it = st.upper_bound(seg[i][0]);
            if(it == st.begin()){
                if(st.size() + 1 <= k){
                    st.insert(seg[i][1]);
                    ans += 1;
                }
            }else{
                it--;
                st.erase(it);
                st.insert(seg[i][1]);
                ans += 1;
            }
        }
    }
    cout << ans << "\n";
}