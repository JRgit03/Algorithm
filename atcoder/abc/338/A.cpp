#include <bits/stdc++.h>
using namespace std;

int main(){
    string s; cin>>s;
    bool suc = (s[0] >= 'A' && s[0] <= 'Z');
    for(int i=1;i<s.length();i++)
        suc &= (s[i] >= 'a' && s[i] <= 'z');
    cout << (suc ? "Yes" : "No") << "\n";
    return 0;
}
