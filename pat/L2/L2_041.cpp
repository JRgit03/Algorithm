#include <bits/stdc++.h>
using namespace std;
const int N = 1010;
int n,m,k;
queue<int> q;
stack<int> stk;

int cnt;
vector<int> res[N];

int main(){
    cin>>n>>m>>k;
    for(int i=0;i<n;i++){
        int x;cin>>x;q.push(x);
    }
    cnt = 1;
    while(q.size() || stk.size()){
        int last = (res[cnt].size() ? res[cnt].back() : 101);
        if(stk.size() && stk.top() <= last){
            int x = stk.top(); stk.pop();
            res[cnt].push_back(x);
        }else if(q.size() && q.front() <= last){
            int x = q.front(); q.pop();
            res[cnt].push_back(x);
        }else if(stk.size() < m && q.size()){
            stk.push(q.front());q.pop();
        }else {
            cnt++;
        }
        if(res[cnt].size()==k)cnt++;
    }
    for(int i=1;i<=cnt;i++){
        if(!res[i].size()) continue;
        cout << res[i][0];
        for(int j=1;j<(int)res[i].size();j++) cout << " " << res[i][j];
        cout << "\n";
    }
    return 0;
}
