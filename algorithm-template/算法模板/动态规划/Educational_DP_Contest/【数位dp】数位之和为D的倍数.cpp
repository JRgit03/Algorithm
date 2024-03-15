const int N = 1e5 + 10, M = 1e2 + 10, mod = 1e9 + 7;
string s;
int m,D;
int memo[N][M];

// 数位dp
// 题目：1和N之间有多少个整数，使得十进制表示的数字之和是D的倍数(等价于数位之和mod D ==0)

void solve(){
    cin>>s>>D;
    m = s.length();
    memset(memo, -1, sizeof memo);
    function<int(int,int,int,int)> f = [&](int i,int sum,int isLimit,int isNum) -> int {
        if(i == m) return sum == 0;
        if(!isLimit && memo[i][sum] != -1) return memo[i][sum] % mod;
        int res = 0;
        int up = isLimit ? s[i] - '0' : 9;
        for(int d=0;d<=up;d++){
            res += f(i+1,(sum+d)%D,isLimit&&d==up,isNum);
            res %= mod;
        }
        if(!isLimit) memo[i][sum] = res;
        return res;
    }; 
    cout << ((f(0, 0, 1, 0) - 1) % mod + mod) % mod  << "\n";
}