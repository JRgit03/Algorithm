#include <bits/stdc++.h>
using namespace std;
const int N = 5e4 + 10;
int n;
int ans[N];

struct Node{
    int id;
    int l,r;

    bool operator < (const Node& o) const {
        return (l != o.l ? l < o.l : r < o.r);
    }
}vec[N];

int main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        int id = i,l,r; cin>>l>>r;
        vec[i] = {id,l,r};
    }    
    sort(vec+1,vec+1+n);
    typedef pair<int,int> PII;
    priority_queue<PII,vector<PII>, greater<PII> > heap; // {结束时间,畜栏编号}
    int tot = 0; // total
    for(int i=1;i<=n;i++){
        if(!heap.size() || heap.top().first >= vec[i].l){
            heap.push({vec[i].r, ++tot});
            ans[vec[i].id] = tot;
        }else{
            auto [ed, id] = heap.top(); heap.pop();
            ans[vec[i].id] = id; heap.push({vec[i].r, id})
        }
    }
    for(int i=1;i<=n;i++) cout << ans[i] << "\n";
    return 0;
}

// 按照开始时间排升序
// 对于当前牛 在已经建立的序列中找到结束时间<当前牛的开始时间 
