/**
 * 模板题
 * https://www.luogu.com.cn/problem/solution/P1939
 * acwing练习题 有代码及推到过程
 * https://www.acwing.com/problem/content/1305/
 */
#include <bits/stdc++.h>
#define int long long
#define IOS ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
using namespace std;
const int N = 10 , Mod = 1e9 + 7;

struct Mat{
    int a[N][N];    
    Mat(){
        memset(a,0,sizeof a);
    }
    void build(){ //构造单位矩阵
        for(int i=1;i<=3;i++) a[i][i] = 1;
    }

    friend Mat operator *(const Mat &x,const Mat &y) {
        Mat res; memset(res.a,0,sizeof res.a); //注意此处要初始化 
        for(int i=1; i<=3; i++)
            for(int j=1; j<=3; j++)
                for(int k=1; k<=3; k++) {
                    res.a[i][j] = (res.a[i][j] + x.a[i][k] * y.a[k][j]) % Mod;
                }
        return res;
    }

    void init(){
        a[1][1] = a[1][3] = a[2][1] = a[3][2] = 1;
    }

    void print(){
        for(int i=1;i<=3;i++) for(int j=1;j<=3;j++) cout << a[i][j] << " \n"[j==3];
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

int B[4][2] = {
    {0,0},
    {0,1},
    {0,1},
    {0,1}
};

void solve(){
    int k;cin>>k;
    if(k<=3) {
        cout << 1 << "\n";
        return;
    }
    Mat a; a.init();
    Mat A = MatrixFastPow(a,k-3);
    int res[4][2];  // 3*3 X 3*1 -> 3 * 1
    memset(res,0,sizeof res);
    for(int i=1;i<=3;i++)
        for(int j=1;j<=1;j++)
            for(int k=1;k<=3;k++)
                res[i][j] = (res[i][j] + A.a[i][k] * B[k][j]) % Mod;
    cout << res[1][1] << "\n";
}

signed main(){
    IOS;
    int t;cin>>t;
    while(t--) solve();
    return 0;
}
