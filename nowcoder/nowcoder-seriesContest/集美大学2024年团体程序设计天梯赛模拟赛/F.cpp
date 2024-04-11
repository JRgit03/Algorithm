#include <bits/stdc++.h>
#define int long long
using namespace std;

int isPascal(string &s){
    return isupper(s[0]);
}

int isSnake(string &s){
    return s.find("_") != -1;
}

string pascalToSnake(string s){
    string str = "";
    for(int i=0;i<s.length();i++){
        if(i == 0) str += tolower(s[0]);
        else{
            if(isupper(s[i])) {
                str += "_";
                str += tolower(s[i]);
            }else{
                str += s[i];
            }
        }
    }
    return str;
}

string camelToSnake(string s){
    string str = "";
    for(int i=0;i<s.length();i++){
        if(isupper(s[i])) {
            str += "_";
            str += tolower(s[i]);
        }else{
            str += s[i];
        }
    }
    return str;
}

string snakeToPascal(string s){
    string str = "";
    for(int i=0;i<s.length();i++){
        if(i == 0){
            str += toupper(s[i]);
        }else{
            if(s[i] == '_'){
                i++;
                str += toupper(s[i]);
            }else{
                str += s[i];
            }
        }
    }
    return str;
}

string snakeToCamel(string s){
    string str = "";
    for(int i=0;i<s.length();i++){
        if(s[i] == '_'){
            i++;
            str += toupper(s[i]);
        }else{
            str += s[i];
        }
    }
    return str;
}

void solve(){
    int n; string t; cin>>n>>t;
    for(int i=0;i<n;i++){
        string s; cin>>s;
        if(isSnake(s)){
            if(t == "Snake") cout << s << "\n";
            else if(t == "Pascal") cout << snakeToPascal(s) << "\n";
            else cout << snakeToCamel(s) << "\n";
        }else if(isPascal(s)){
            s = pascalToSnake(s);
            if(t == "Snake") cout << s << "\n";
            else if(t == "Pascal") cout << snakeToPascal(s) << "\n";
            else cout << snakeToCamel(s) << "\n";
        }else{
            s = camelToSnake(s);
            if(t == "Snake") cout << s << "\n";
            else if(t == "Pascal") cout << snakeToPascal(s) << "\n";
            else cout << snakeToCamel(s) << "\n";
        }
    }
}

signed main(){
    solve();
    return 0;
}
