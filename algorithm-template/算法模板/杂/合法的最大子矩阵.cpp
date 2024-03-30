/*《直方图的最大矩阵》加强版
 * 给定n*m的地图初始为空,存在p个障碍物点,求不包含障碍物的最大子矩阵 
 * n,m <= 3000, p <= 300000
 */
const int N = 3e3 + 10;
int n,m,p;
int g[N][N]; // g[i,j] = 1 表示 第(i,j)点存在障碍物
int h[N][N]; // h[i,j] 表示以第i行为基准/底,向上的最大高度
int l[N],r[N],stk[N],tt; // l[i]/r[i] 左边/右边第一个严格小于h[i]的下标 

void solve(){
    cin>>n>>m>>p;
    while(p--) {
        int x,y; cin>>x>>y;
        g[x][y] = 1;
    }
    // 预处理
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++){
            if(g[i][j] == 0) h[i][j] = h[i-1][j] + 1;
            else h[i][j] = 0;
            // cout << i << " " << j << " " << h[i][j] << "\n";
        }
    // 枚举行 一行行处理
    int ans = 0;
    for(int i=1;i<=n;i++){
        tt = 0; for(int j=1;j<=m;j++) {
            while(tt > 0 && h[i][stk[tt]] >= h[i][j]) tt -= 1;
            l[j] = (tt > 0 ? stk[tt] : 0);
            stk[++tt] = j;
        }
        tt = 0; for(int j=m;j>=1;j--) {
            while(tt > 0 && h[i][stk[tt]] >= h[i][j]) tt -= 1;
            r[j] = (tt > 0 ? stk[tt] : m+1);
            stk[++tt] = j;
        }
        for(int j=1;j<=m;j++){
            int len = j - l[j] + r[j] - j - 1;
            ans = max(ans, h[i][j] * len);
        }
    }
    cout << ans << "\n";
}