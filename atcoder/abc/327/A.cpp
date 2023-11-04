#include <bits/stdc++.h>
using namespace std;

int main(){
    int n; cin>>n;
    string s; cin>>s;
    cout << ((s.find("ab") != -1 || s.find("ba") != -1) ? "Yes" : "No") << "\n";
    return 0;
}
