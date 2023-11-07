#include <bits/stdc++.h>
using namespace std;

int main(){
    int n; cin>>n;
    vector<int> vec(n);
    for(int i=1;i<=n;i++) vec.push_back(i);
    cout << vec.size() << "\n";
    for(auto x : vec) cout << x << " ";
    return 0;
}
