#include <bits/stdc++.h>
using namespace std;

string s; 

bool is_number(char ch) {
    return ch >= '0' && ch <= '9';
}

bool is_RXCY(string s){
    bool flag=false; // 表示以'R'开头,C之间是否存在数字
    if(s[0]!='R') return false;
    if(!is_number(s[1])) return false;
    for(int i=1;i<s.size();i++){
        if(is_number(s[i])&&(!flag)) flag=true;
        else if(flag&&s[i]=='C') return true;
    }
    return false;
}

// 字母(列)数字(行) -> RXCY
void f(){
    int k = 0; while(1) {
        if(s[k] >= '1' && s[k] <= '9') break;
        k += 1;
    }
    string pre = s.substr(0,k), suf = s.substr(k); 
    int r = stoi(suf), c = 0; for(auto ch : pre) c = c * 26 + ch - 'A' + 1;
    string ans = "R" + to_string(r) + "C" + to_string(c);
    cout << ans << "\n";
}

// RXCY -> 字母(列)数字(行) 
void g(){ 
    int k = s.rfind('C');
    string ansr = s.substr(1,k-1), suf = s.substr(k+1), ansl = ""; 
    int r = stoi(suf); 
    while(r) {
        int x = r % 26; if(x == 0) x = 26; // 特判： 当前位为'Z' 不减则下一位比实际值大1
        ansl += char('A' + x - 1); 
        r /= 26; if(x == 26) r--;
    } reverse(ansl.begin(), ansl.end());
    string ans = ansl + ansr;
    cout << ans << "\n";
}

void solve(){
    cin>>s;
    if(is_RXCY(s)) g();
    else f();
}

int main(){
    int t; cin>>t;
    while(t--) solve();
    return 0;
}
