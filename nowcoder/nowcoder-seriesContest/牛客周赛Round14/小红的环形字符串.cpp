#include <bits/stdc++.h>
using namespace std;

int main(){
    int n; cin>>n;
    string s; cin>>s;
    deque<char> q; int ans = 0; 
    for(int i=0;i<n;i++){
        if(!i) q.push_back(s[i]);
        else{
            if(!q.size()) q.push_back(s[i]);
            else{
                if(q.back() == s[i]){
                    q.pop_back();
                    ans += 2;
                }else{
                    q.push_back(s[i]);
                }
            }
        }
    }
    while(q.size()){
        if(q.size() == 1) break;
        char l = q.front() , r = q.back();
        if(l == r) {
            ans += 2;
            q.pop_back(); 
            q.pop_front();
        }else{
            break;
        }
    }
    cout << ans << "\n";
    return 0;
}
