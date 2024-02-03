#include <bits/stdc++.h>
using namespace std;
int n;
string g[100];
int hh,tt;
tuple<int,int,int,int,int> q[1000000 + 10];
int dx[4] = {-1,0,1,0}; 
int dy[4] = {0,1,0,-1};

int gethash(int a,int b,int c,int d){
    return a * 60 * 60 * 60 + b * 60 * 60 + c * 60 + d;
}

pair<int,int> move(int x,int y,int dir){
    int u = x + dx[dir], v = y + dy[dir];
    if(u >= 0 && u < n && v >= 0 && v < n && g[u][v] != '#') return {u,v};
    return {x,y};
}

int main(){
    cin>>n;
    int a = -1,b,c,d;
    for(int i=0;i<n;i++) {
        cin>>g[i];
        for(int j=0;j<n;j++)
            if(g[i][j] == 'P'){
                if(a == -1){
                    a = i, b = j;
                } else {
                    c = i, d = j;
                }
            } 
    }    
    set<int> st; st.insert(gethash(a,b,c,d));
    queue<tuple<int,int,int,int,int>> q; q.push({a,b,c,d,0});
    while(q.size()){
        auto [a,b,c,d,cnt] = q.front(); q.pop();

        if(a == c && b == d){
            cout << cnt << "\n";
            return 0;
        }
        
        for(int i=0;i<4;i++){
            auto [e,f] = move(a,b,i);
            auto [g,h] = move(c,d,i);
            if(!st.count(gethash(e,f,g,h))){
                st.insert(gethash(e,f,g,h));
                q.push({e,f,g,h,cnt+1});
            }
        }
    }
    cout << -1 << "\n";
    return 0;
}
