#include <bits/stdc++.h>
using namespace std;

int main(){
    vector<int> v(5); for(auto &x : v) cin>>x;
    int s = 0; for(int i=0;i<4;i++){
        int x; cin>>x; 
        if(i != 3) s += v[i] * x;
        else s -= v[i] * x;
    }
    cout << (s > v[4] ? "YES" : "NO") << "\n";
    return 0;
}
