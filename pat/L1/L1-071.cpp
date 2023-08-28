#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,q;cin>>n>>q;
    while(q--){
        string str;cin>>str;
        int v = 0;
        for(auto c : str) v = (v<<1) + (c=='n');
        cout << v+1 << "\n";
    }
    return 0;
}
