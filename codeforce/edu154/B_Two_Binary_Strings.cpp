#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
using namespace std;
typedef long long ll;

void solve(){
    string a,b;cin>>a>>b;
    int n = a.length();

    vector<int> v1,v0;
    for(int i=0;i<n;i++){
        if(a[i] == b[i]){
            if(a[i] == '0'){
                v0.push_back(i);
            }else{
                v1.push_back(i);
            }
        }
    }

    for(int i=0;i<v0.size();i++){
        for(int j=0;j<v1.size();j++){
            if(v0[i] + 1 == v1[j]){
                cout << "YES" << "\n";
                return;
            }
        }
    }

    cout << "NO" << "\n";
    return;
}

int main(){
    IOS;
    int t;cin>>t;
    while(t--)solve();
    return 0;
}
