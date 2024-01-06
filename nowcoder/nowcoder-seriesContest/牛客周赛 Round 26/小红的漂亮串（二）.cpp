#include <bits/stdc++.h>
using namespace std;

int cnt;
void dfs(int i,int j,string s){
    if(i == j){
        int k = s.find("red"); if(k == -1) return;
        k = s.find("red",k+1); if(k == -1) return;
        cnt += 1; return;
    }
    for(char c = 'a'; c <= 'z'; c++){
        s.push_back(c);
        dfs(i+1,j,s);
        s.pop_back();
    }
}

int main(){
    for(int len=1;len<=7;len++){
        cnt = 0; dfs(0,len,"");
        cout << len << " " << cnt << "\n";
    }
    return 0;
}
