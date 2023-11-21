#include <bits/stdc++.h>
using namespace std;

int main(){
    int n; cin>>n;
    vector<int> vec(n);
    for(auto &x : vec) cin>>x;
    sort(vec.begin(),vec.end(),greater<int>());
    for(int i=0;i<n;i++){
        if(vec[i] != vec[0]){
            cout << vec[i] << "\n";
            return 0;
        }
    }
    return 0;
}
