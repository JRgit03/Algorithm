#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
using namespace std;
typedef long long ll;

void solve(){
    
}

int main(){
    vector<int> vec;
    int n = 10;
    for(int i=1;i<=n;i++) vec.push_back(i*2);
    cout << lower_bound(vec.begin(),vec.end(),22) << "\n";
    return 0;
}
