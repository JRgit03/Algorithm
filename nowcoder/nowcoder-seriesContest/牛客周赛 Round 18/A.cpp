#include <bits/stdc++.h>
using namespace std;

int main(){
    string s; cin>>s;
    int k; cin>>k;
    reverse(s.begin(),s.begin()+k);
    cout << stoi(s) << "\n";
    return 0;
}
