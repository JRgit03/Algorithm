#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0); 
#define int long long
using namespace std;

int max(int a,int b){return (a > b ? a : b); }
int min(int a,int b){return (a < b ? a : b); }

const int N = 5e5 + 10;
int n,k;
int a[N];
int l[N],r[N];

struct Node{
    int val, id;
    
    bool operator < (const Node& o) const {
        return (val != o.val ? val > o.val : id > o.id);
    }
};

void solve(){
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        l[i] = i - 1;
        r[i] = i + 1;
    }
    r[0] = 1; 
    l[n+1] = n;
    priority_queue<Node> heap;
    for(int i=1;i<=n;i++) heap.push({a[i], i});
    for(int i=0;i<k;i++){
        while(heap.size() && heap.top().val != a[heap.top().id]) heap.pop();
        int v = heap.top().val, id = heap.top().id; heap.pop();
        
        a[l[id]] += v; a[r[id]] += v;
        if(l[id] != 0) heap.push({a[l[id]], l[id]});
        if(r[id] != n+1) heap.push({a[r[id]], r[id]});
        r[l[id]] = r[id]; 
        l[r[id]] = l[id];
    }
    int x = 0;
    while(r[x] != n+1){
        cout << a[r[x]] << " ";
        x = r[x];
    }
}

signed main(){
    IOS; solve();
    return 0;
} 

/*
5 3
1 4 2 8 7
*/
