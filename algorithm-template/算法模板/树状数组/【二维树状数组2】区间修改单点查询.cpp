// 题意：
// 给定 n * m 的 零矩阵A 完成如下操作
// op1: 1 a b c d k 表示 以(a,b)为左上角,(c,d)为右上角的子矩阵内所有数 + k
// op2: 2 x y 询问 a[x,y]
// 使用差分的思想
int n,m,c[N][N];
int lowbit(int x){ return x & -x; }

void add(int x, int y, int v) {
	for (int i = x; i <= n; i += lowbit(i))
		for (int j = y; j <= m; j += lowbit(j))
			c[i][j] += v;
}

int sum(int x, int y) {
	int res = 0;
	for (int i = x; i > 0; i -= lowbit(i))
		for (int j = y; j > 0; j -= lowbit(j))
			res += c[i][j];
	return res;
}

void solve() {
	cin >> n >> m;
    int op; while(cin >> op){
        if(op == 1){
            int a,b,c,d,k; cin>>a>>b>>c>>d>>k;
            add(a,b,k); add(c+1,b,-k); add(a,d+1,-k); add(c+1,d+1,k);
        }else{
            int x,y; cin>>x>>y;
            cout << sum(x,y) << "\n";
        }
    }
}