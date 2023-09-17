#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
using namespace std;
typedef long long ll;

string s;
int n;
int num1,num2,Mod;
int memo[20][110];

int f(int i,int sum,int isLimit,int isNum){
    if(i == n) return sum % Mod == 0;
    if(!isLimit && memo[i][sum] != -1) return memo[i][sum];
    
    int res = 0;
    int up = isLimit ? s[i] - '0' : 9;
    for(int d=0;d<=up;d++)
        res += f(i+1,sum+d,isLimit&(d==up),isNum);

    if(!isLimit) memo[i][sum] = res;
    return res;
}

int check(int x){
    int sum = 0; string s = to_string(x);
    for(int i=0;i<s.length();i++)
        sum += s[i] - '0';
    return sum % Mod == 0;
}

int main(){
    IOS; while(cin>>num1>>num2>>Mod){
        s = to_string(num2); n = s.length(); memset(memo,-1,sizeof memo); int ansr = f(0,0,1,0);
        s = to_string(num1); n = s.length(); memset(memo,-1,sizeof memo); int ansl = f(0,0,1,0);
        cout << ansr - ansl + check(num1) << "\n";
    }
    return 0;
}
