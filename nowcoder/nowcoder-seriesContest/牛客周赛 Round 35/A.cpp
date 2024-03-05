#include <bits/stdc++.h>
using namespace std;

int main(){
    string s; cin>>s;
    int n = s.length(); 
    cout << s.substr(0, n / 2) << " " << s.substr(n/2) << "\n";
    return 0;
}
