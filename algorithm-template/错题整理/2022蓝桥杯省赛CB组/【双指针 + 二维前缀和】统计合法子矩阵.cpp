/*
    题意：给定一个 N×M 的矩阵 A，请你统计有多少个子矩阵 (最小 1 × 1，最大 N × M) 满足子矩阵中所有数的和不超过给定的整数K
         n,m <= 500, k <= 2.5e8
    思路：预处理二维前缀和, 枚举子矩阵上下边界，使用同向双指针维护单调性 类似于字段和的思想
*/
const int N = 5e2 + 10;
int n,m,k;
int a[N][N];
int s[N][N];

int ask(int x1,int y1,int x2,int y2){
	return s[x2][y2] - s[x1 - 1][y2] - s[x2][y1 - 1] + s[x1 - 1][y1 - 1];
}

void solve(){
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			cin>>a[i][j];
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			s[i][j] = s[i-1][j] + s[i][j-1] - s[i-1][j-1] + a[i][j];
	int ans = 0;
	for(int x1=1;x1<=n;x1++){ // 枚举上边界 
		for(int x2=x1;x2<=n;x2++){ // 枚举下边界 
			for(int r=1,l=1;r<=m;r++){ // 同向双指针维护数组字段和<=k;
				while(l <= r && ask(x1,l,x2,r) > k) l += 1;
				if(l <= r && ask(x1,l,x2,r) <= k) ans += r - l + 1; 
			} 
		}
	}
	cout << ans << "\n";
}