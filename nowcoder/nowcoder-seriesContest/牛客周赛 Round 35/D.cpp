#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int n;
int a[N];
int st[N];

int main(){
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    vector<int> v;
    for(int i=1;i<=n;i++){
        if(a[i] > n) v.push_back(i);
        else {
            if(!st[a[i]]) st[a[i]] = 1;
            else v.push_back(i);
        }
    }   
    vector<pair<int,int>> ans;
    int j = 0; 
    for(int i=1;i<=n;i++) 
        if(!st[i]){
            ans.push_back({v[j++], i});
        }
    cout << ans.size() << "\n";
    for(auto [a,b] : ans) cout << a << " " << b << "\n";
    return 0;
}
