#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main(){
    int n,m;cin>>n>>m; //m的n进制表示

    if(n==2){
        cout << "YES" << "\n";return 0;
    }

    vector<int> vec;
    while(m){
        int x = m%n;
        vec.push_back(x);
        m/=n;
    }

    //reverse(vec.begin(),vec.end());
    //for(auto &x : vec) cout << x << "\n";

    for(int i=0;i<(int)vec.size();i++){
        int x = vec[i];
        if(x==1 || x==0) continue;
        else if(x==n-1 || x==n){
            if(i+1<(int)vec.size())vec[i+1] += 1;
            else vec.push_back(1);
        }else{
            cout << "NO" << "\n";return 0;
        }
    }
    cout << "YES" << "\n";return 0;   
}
