#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n, m, a, b, c;
    cin >> n >> m;
    cout << "? 1 1" << endl;
    cin >> a;
    cout << "? 1 " << min(a+1, m) << endl;
    cin >> b;
    cout << "? " << min(a+1, n) << " 1" << endl;
    cin >> c;
    cout << "! " << b + 1 << " " << c + 1 << endl; 
}

int main(){int t;cin>>t;while(t--)solve();return 0;}