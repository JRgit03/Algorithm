#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define int long long
using namespace std;

int max(int a,int b){return a > b ? a : b;}
int min(int a,int b){return a < b ? a : b;}

const int N = 1e5 + 10;
int n,p,q;
int h[N];

void solve(){
    cin>>n>>p>>q;
    priority_queue<int> heap;
    for(int i=1;i<=n;i++){
        cin>>h[i]; heap.push(h[i]);
    } 
    while(heap.size() && (p > 0 || q > 0)){
        int t = heap.top(); heap.pop();
        if(p > 0 && q > 0){
            int px = sqrt(t), qx = t / 2;
            if(px < qx) heap.push(px), p--;
            else heap.push(qx), q--;
        }else if(p > 0){
            int px = sqrt(t);
            heap.push(px); p--;
        }else{
            int qx =  t / 2;
            heap.push(qx); q--;
        }
    }
    int ans = 0;
    while(heap.size()){
        int t = heap.top(); heap.pop(); 
        //cerr << t << "\n";
        ans += t;
    }
    cout << ans << "\n";
}

// AC 92
signed main(){
    IOS;
    solve();
    return 0;
} 
/*
4 1 1
4 5 6 49
*/
