#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = (1 << 12) + 10;
int n,m;
//给定一个大小为 N * M 的零矩阵，直到输入文件结束，你需要进行若干个操作，操作有两类：
//1 a b c d x，表示将左上角为 (a,b)，右下角为 (c,d) 的子矩阵全部加上 x；
//2 a b c d，表示询问左上角为 (a,b)，右下角为 (c,d) 为顶点的子矩阵的所有数字之和。
typedef long long ll;
ll t1[N][N], t2[N][N], t3[N][N], t4[N][N];

ll lowbit(ll x){ return x & (-x);}

void add(ll x, ll y, ll z) {
  for (int X = x; X <= n; X += lowbit(X))
    for (int Y = y; Y <= m; Y += lowbit(Y)) {
      t1[X][Y] += z;
      t2[X][Y] += z * x;  // 注意是 z * x 而不是 z * X，后面同理
      t3[X][Y] += z * y;
      t4[X][Y] += z * x * y;
    }
}

void range_add(ll xa, ll ya, ll xb, ll yb,
               ll z) {  //(xa, ya) 到 (xb, yb) 子矩阵
  add(xa, ya, z);
  add(xa, yb + 1, -z);
  add(xb + 1, ya, -z);
  add(xb + 1, yb + 1, z);
}

ll ask(ll x, ll y) {
  ll res = 0;
  for (int i = x; i; i -= lowbit(i))
    for (int j = y; j; j -= lowbit(j))
      res += (x + 1) * (y + 1) * t1[i][j] - (y + 1) * t2[i][j] -
             (x + 1) * t3[i][j] + t4[i][j];
  return res;
}

ll range_ask(ll xa, ll ya, ll xb, ll yb) {
  return ask(xb, yb) - ask(xb, ya - 1) - ask(xa - 1, yb) + ask(xa - 1, ya - 1);
}

signed main(){
    cin>>n>>m;
    int op; while(cin>>op){
        int a,b,c,d,x; cin>>a>>b>>c>>d;
        if(op == 1){
            cin>>x; range_add(a,b,c,d,x);
        }else{
            cout << range_ask(a,b,c,d) << "\n";
        }
    }
    return 0;
}

