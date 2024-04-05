#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define int long long
using namespace std;

int max(int a,int b){ return (a > b ? a : b);}
int min(int a,int b){ return (a < b ? a : b);}

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

signed main(){
	IOS;
	solve();
	return 0;
} 

/*
6
2 1 4 2 6 7
*/
