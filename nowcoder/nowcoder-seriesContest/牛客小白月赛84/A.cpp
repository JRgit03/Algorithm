#include <bits/stdc++.h>
using namespace std;

int main(){
    int t; cin>>t; for(int i=0;i<t;i++){
        int n,m,x,y; cin>>n>>m>>x>>y;
        cout << (x >= y && x + n - m >= y ? "Yes" : "No") << "\n"; 
    }
    return 0;
}
