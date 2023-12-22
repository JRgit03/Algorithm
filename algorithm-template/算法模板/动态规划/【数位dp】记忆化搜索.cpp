// 给定正整数 n，返回在 [1, n] 范围内具有 至少 1 位 重复数字的正整数的个数
class Solution {
public:
    string s;
    int m; //n的最高位数
    int memo[10][1<<10]; //记忆化搜索 记录f[i,mask]状态防止重复计算 状态压缩

    //返回从i开始填数字，i前面填的数字结合为mask,能够构造出合法整数数目
    //isLimit 表示前面填的数字是否(都是)n对应位置上的，如果为true，则当前为至多为int(s[i]),否则至多为9
    //isNum表示前面是否填了数字(是否跳过),如果为true，则当前位可以从0开始，如果为false可以跳过/或者从1开始填数  有前导0的不为合法数
    //记录状态的条件 ： 为什么只记录isLimit为false的情况 ，因为函数递归isLimit为true会一直递归下去
    //                 当然也可以记录四维状态 , 定为二维节省空间
    //                 由于前导零对答案有影响，isNum 不可以省略
    //                 从高位开始枚举
    int f(int i,int mask,int isLimit,int isNum){
        if(i==m) return isNum; //isNum为true表示是合法数字
        if(!isLimit && isNum && memo[i][mask]!=-1) return memo[i][mask];
        
        int res = 0;
        if(!isNum) res = f(i+1,mask,false,false);
        
        int up = isLimit ? s[i] - '0' : 9; //上界处理
        for(int d=1-isNum;d<=up;d++)
            if(!((mask >> d) & 1)) //d不在mask中
                res += f(i+1,mask|(1<<d),isLimit&&d==up,1);
                
        if(!isLimit && isNum)
            memo[i][mask] = res; //记录状态
        return res;
    }

    int numDupDigitsAtMostN(int n) {
        memset(memo,-1,sizeof memo);
        s = to_string(n); m = s.length();
        return n - f(0,0,1,false); // n - 没有重复数字的个数
    }
};

// 给定一个按 非递减顺序 排列的数字数组 digits 。你可以用任意次数 digits[i] 来写的数字。
//例如，如果 digits = ['1','3','5']，我们可以写数字，如 '13', '551', 和 '1351315'。
//返回 可以生成的小于或等于给定整数 n 的正整数的个数 。

class Solution {
public:
    int atMostNGivenDigitSet(vector<string>& digits, int n) {
        string s = to_string(n); int m = s.length();
        int memo[m+1]; memset(memo,-1,sizeof memo);

        function<int(int,int,int)> f = [&](int i,int isLimit,int isNum) -> int {
            if(i == m) return isNum;
            if(!isLimit && isNum && memo[i] != -1) return memo[i];
            
            int res = 0;
            if(!isNum) res = f(i+1,0,0);

            char up = isLimit ? s[i] : '9';
            for(auto &c : digits){
                if(c[0] > up && isLimit) continue;
                res += f(i+1,isLimit&(c[0]==up),1);
            }

            if(!isLimit && isNum) memo[i] = res;
            return res;
        };
        return f(0,1,0);
    }
};

//给定一个正整数 n ，请你统计在 [0, n] 范围的非负整数中，有多少个整数的二进制表示中不存在 连续的 1 
class Solution {
public:

    int n;
    int m; string s;
    int dp[33][2];

    int f(int i,int pre,int isLimit){
        if(i<0) return 1;
        if(!isLimit && dp[i][pre] != -1) return dp[i][pre];
        
        int up = isLimit ? n>>i&1 : 1;
        int res = f(i-1,0,isLimit&&up==0); //填0
        if(!pre && up==1) res += f(i-1,1,isLimit);

        if(!isLimit) dp[i][pre] = res;        
        return res;
    }

    int findIntegers(int x) {
        memset(dp,-1,sizeof dp); n = x;
        s = to_string(x) ; m = __lg(x); // __lg 等于 log2 向上取整
        return f(m,0,1);
    }
};

// 给定闭区间[a,b] 求各个数字数位之和modN为0的个数
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
