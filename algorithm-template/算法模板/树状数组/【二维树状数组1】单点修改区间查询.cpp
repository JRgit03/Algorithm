// 题意：
// 给定 n * m 的 零矩阵A 完成如下操作
// op1: 1 x y k 表示 a[x,y] += k
// op2: 2 a b c d 表示 询问以(a,b)为左上角,(c,d)为右上角的子矩阵之和
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

int ask(int x1, int y1, int x2, int y2) {
	return sum(x2, y2) - sum(x2, y1 - 1) - sum(x1 - 1, y2) + sum(x1 - 1, y1 - 1);
}

void solve() {
	cin >> n >> m;
    int op; while(cin >> op){
        if(op == 1){
            int x,y,k; cin>>x>>y>>k;
            add(x,y,k);
        }else{
            int a,b,c,d; cin>>a>>b>>c>>d;
            cout << ask(a,b,c,d) << "\n";
        }
    }
}