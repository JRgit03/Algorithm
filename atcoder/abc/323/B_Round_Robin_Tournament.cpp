#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
using namespace std;

void solve(){
    typedef pair<int,int> PII;
    int n; cin>>n;
    vector<PII> vec(n);
    for(int i=0;i<n;i++){
        string s; cin>>s;
        vec[i] = {i,0};
        for(int j=0;j<n;j++){
            vec[i].second += (s[j] == 'x');
        }
    }
    sort(vec.begin(),vec.end(),[&](PII p,PII q){
       return p.second != q.second ? p.second < q.second : p.first < q.first; 
    });
    for(int i=0;i<n;i++) cout << vec[i].first + 1 << " ";
}

int main(){
    IOS; solve();
    return 0;
}
