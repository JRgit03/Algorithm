#include <bits/stdc++.h>
using namespace std;

int main(){
    int res = 0 , first = -1 , cur = 0;
    string str;while(getline(cin,str)){
        if(str==".")break;
        cur++;
        if(str.find("chi1 huo3 guo1")!=-1){
            res++;
            if(first==-1)first=cur;
        }
    }
    cout << cur << "\n";
    if(!res) cout << "-_-#" << "\n";
    else cout << first << " " << res << "\n";
    return 0;
}
