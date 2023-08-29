#include <bits/stdc++.h>
#define int long long
#define IOS ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
using namespace std;
const int N = 110 , Mod = 1e9 + 7;
int n,b;

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
                    res.a[i][j] = (res.a[i][j] + x.a[i][k] * y.a[k][j]) % Mod;
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

signed main(){
    IOS;
    cin>>n>>b;
    Mat a; a.init(); 
    MatrixFastPow(a,b).print();
    return 0;
}
