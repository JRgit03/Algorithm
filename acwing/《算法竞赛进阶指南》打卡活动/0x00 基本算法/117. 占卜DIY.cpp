#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> PII;
int cnt[1100];
deque<PII> q[110]; // [val,st] ...

int get(char c){
    if(c == 'A') return 1;
    if(c == '0') return 10;
    if(c == 'J') return 11;
    if(c == 'Q') return 12;
    if(c == 'K') return 13;
    return c - '0';
}

int main(){
    for(int i=1;i<=13;i++)
        for(int j=0;j<4;j++){
            char c; cin>>x;
            q[i].push_back({get(x),0});
        }    
    for(int i=1;i<=4;i++){
        int x = q[13].front().first; cnt[x] += 1; q[13].pop_front();
        while(x < 13){
            int t = q[x].back().first; q[x].pop_back();
            x = t;
            if(x == 13) break;  
            q[x].push_front({x,1});
        }
    }
    for(int i=1;i<13;i++)
        while(q[i].size()){
            auto [val,st] = q[i].front(); q[i].pop_front();
            if(st == 1) cnt[val] += 1;
        }
    int ans = 0;
    for(int i=1;i<13;i++) ans += (cnt[i] == 4);
    cout << ans << "\n";
    return 0;
}
