#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 110 , mod = 1e9 + 7;
int n,k;

// 题意：给一张有向简单图，给出邻接矩阵，求长度为 K 的路径条数，答案对1e9+7取模。
// n <= 50, k <= 1e18
// f[t,i,j] 表示 从点i到点j长度为t的方案数
// f[t,i,j] = sum( f[t-1][i][k] * f[1][k][j] ) k为中转点
// 显然 ft = ft-1 * f1 => fk = f1 ^ k
// 所有合法方案数 sum( f[k][i][j] ) 1 <= i,j <= n
// O(n ^ 3 * logk)
struct Mat{
    int a[N][N];    
    Mat(){
        memset(a,0,sizeof a);
    }
    void build(){ //构造单位矩阵
        for(int i=1;i<=n;i++) a[i][i] = 1;
    }
    friend Mat operator *(const Mat &x, const Mat &y) {
        Mat res;
        for(int i=1; i<=n; i++)
            for(int j=1; j<=n; j++)
                for(int k=1; k<=n; k++) {
                    res.a[i][j] = (res.a[i][j] + x.a[i][k] * y.a[k][j]) % mod;
                }
        return res;
    }

    void init(){
        for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) cin>>a[i][j];
    }

    void print(){
        for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) cout << a[i][j] << " \n"[j==n];
    }
};

Mat MatrixFastPow(Mat &a,int b){ // a^b
    Mat res; res.build();
    while(b){
        if(b&1) res = res * a;
        a = a * a;
        b >>= 1;
    }
    return res;
}

void solve(){
    cin>>n>>k;
    Mat mat = Mat();
    mat.init();
    Mat z = MatrixFastPow(mat, k);
    int ans = 0;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++){
            ans += z.a[i][j];
            ans %= mod;
        }
    cout << ans << "\n";
}

signed main(){
    solve();
    return 0;
}
