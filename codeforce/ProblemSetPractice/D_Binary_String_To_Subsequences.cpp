#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
using namespace std;
typedef long long ll;

void solve(){
    int n; cin>>n;
    vector<int> ans(n+1);
    string str; cin>>str; str = "?" + str;
    stack<int> s0,s1;
    for(int i=1;i<=n;i++){
        int x = str[i] - '0';
        //cout << i << " " << x << " " << s0.size() << " " << s1.size() << "\n";
        if(!x){
            if(s1.size()){
                int t = s1.top(); s1.pop();
                ans[i] = t; s0.push(t); 
            }else{
                ans[i] = s0.size() + s1.size() + 1; s0.push(ans[i]); 
            }
        }else{
            if(s0.size()){
                int t = s0.top(); s0.pop();
                ans[i] = t; s1.push(t); 
            }else{
                ans[i] = s0.size() + s1.size() + 1; s1.push(ans[i]); 
            } 
        }
    }
    cout << s0.size() + s1.size() << "\n";
    for(int i=1;i<=n;i++) cout << ans[i] << " \n"[i==n];
}

int main(){
    IOS;
    int t;cin>>t;
    while(t--)solve();
    return 0;
}
