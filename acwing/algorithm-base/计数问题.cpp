#include <bits/stdc++.h>
using namespace std;
const int N = 11;
string s; int m;
int memo[N][N]; //记忆化搜索 memo[i][j] 数字x前i个位置出现的次数为j的状态是否出现过

int f(int x,int i,int cnt,bool isLimit,bool isNum){
    if(i==m) return cnt; //是否合法均可返回cnt , isNum为false是cnt为0

    if(!isLimit && isNum && memo[i][cnt] != -1) return memo[i][cnt];
    
    int res = 0;
    if(!isNum) res = f(x,i+1,cnt,false,false);
    
    int up = isLimit ? s[i] - '0' : 9;
    for(int d=1-isNum;d<=up;d++)
        res += f(x,i+1,cnt+(d==x),isLimit&&d==up,true);

    if(!isLimit && isNum)  memo[i][cnt] = res;
    return res;
}

int calc(int x,int n){ //处理1~n有多少个数字x
    memset(memo,-1,sizeof memo); s = to_string(n); m = s.length();
    return f(x,0,0,true,false);
}

int main(){
    int a,b;while(cin>>a>>b){ //求a~b之间有多少个数字x
        if(!a && !b)break;
        for(int x=0;x<=9;x++) cout << calc(x,b) - calc(x,a-1) << " \n"[x==9]; 
    }
    return 0;
}
