#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
using namespace std;
typedef long long ll;
string line,t,s;

void change(string &s){
    for(auto &c : s) c = tolower(c);
}

bool check(string s){
    if(s == "i") return true;
    if(s.length() == 2){
        if(s[0] == 'i'){
            if(s[1] == '.' || s[1] == ',') return true;
            return false;
        }
    }
    return false;
}

void solve(){
    stringstream ss(line);
    vector<string> ans;
    int f = 0;
    while(ss >> s){
        if(!f) {
            f = 1; change(s); s[0] = toupper(s[0]);
        }else{
            change(s);
            if(check(s)) s[0] = toupper(s[0]);
        }
        if(s.back() == '.') f = 0;
        ans.push_back(s);
    }
    for(int i=0;i<ans.size();i++) {
        cout << ans[i];
        if(i < ans.size() - 1) cout << " ";
    }
    cout << "\n";
}

int main(){
    IOS;
    while(getline(cin,line)) solve();
    return 0;
}
