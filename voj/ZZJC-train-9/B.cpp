#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
using namespace std;

int main(){
    IOS;
    string s;cin>>s;
    int len = s.length();
    for(int i=0;i<len;i++){
        char c = s[i];
        if(i<2)cout<<c;
        else{
            string str = s.substr(i-2,3);
            cout<<c;
            if(str=="cjb")cout<<",";
        }
    }
    return 0;
}
