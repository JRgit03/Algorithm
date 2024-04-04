/*
    题意：给定n颗竹子,每颗竹子高hi,你可以使用魔法选择一段高度相同的柱子，使得 H = int(sqrt(H / 2 + 1))
          求给定n颗竹子高度全变1的最小操作次数 n<=2e5, hi<=1e18
    思路：显然要优先处理高的竹子,同时处理左右高度一致的竹子,启发使用优先队列模拟
*/
struct Node{
    int h, id;
    bool operator < (const Node& o) const {
        return h != o.h ? h < o.h : id < o.id;
    }
};

void solve(){
    int n; cin>>n;
    priority_queue<Node> heap;
    for(int i=0;i<n;i++){
        int x; cin>>x;
        heap.push({x,i+1});
    }
    int ans = 0;
    while(heap.top().h != 1){
        ans += 1;
        int h = heap.top().h, id = heap.top().id; heap.pop();
        int hh = sqrt(h / 2 + 1);
        heap.push({hh, id});
        while(heap.top().h != 1 && heap.top().h == h && heap.top().id == id - 1){
            heap.pop(); 
            heap.push({hh, --id});
        }
    }
    cout << ans << "\n";
}