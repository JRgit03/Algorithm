#include <bits/stdc++.h>
using namespace std;

int main(){
    int n; cin>>n; n = n * 2;
    vector<int> vec(n); for(auto &x : vec) cin>>x;           
    int cnt1 = 0, cnt2 = 0; // cnt1 1开头的情况
    for(int i=0;i<n;i+=2){
        if(vec[i] == 0) cnt1++;
        if(vec[i+1] == 0) cnt2++;
    }
    cout << min(cnt1,cnt2) << "\n"; 
    return 0;
}
