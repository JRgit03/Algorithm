#include <bits/stdc++.h>
using namespace std;

int main(){
    string str;cin>>str;
    for(auto &c : str)
        if(isupper(c))
            c = tolower(c);
    if(str.length() >= 6 && str.substr(0,6) == "lovely") cout << "lovely" << "\n";
    else cout << "ugly" << "\n";
    return 0;
}
