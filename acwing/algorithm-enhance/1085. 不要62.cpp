#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
using namespace std;
typedef long long ll;
const int N = 20;
string s;
int n;
int num1,num2;
int memo[N][N];

// 本题 前导0不影响结果 即isNum参数可以省略
int f(int i,int pre,int isLimit,int isNum){
    if(i == n) return 1;
    if(!isLimit && memo[i][pre] != -1) return memo[i][pre];
    
    int res = 0;
    int up = isLimit ? s[i] - '0' : 9;
    for(int d=0;d<=up;d++){
        if(d == 4) continue;
        if(d == 2 && pre == 6) continue;
        res += f(i+1,d,isLimit&(d==up),isNum);
    }
    if(!isLimit) memo[i][pre] = res;
    return res; 
}

int check(int x){
    string s = to_string(x);
    return !(s.find("4") != -1 || s.find("62") != -1);
}

int main(){
    IOS; while(cin>>num1>>num2){
        if(!num1 && !num2) break;
        s = to_string(num2); n = s.length(); memset(memo,-1,sizeof memo); int ansr = f(0,10,1,0);
        s = to_string(num1); n = s.length(); memset(memo,-1,sizeof memo); int ansl = f(0,10,1,0);
        cout << ansr - ansl + check(num1) << "\n";
    }
    return 0;
}
