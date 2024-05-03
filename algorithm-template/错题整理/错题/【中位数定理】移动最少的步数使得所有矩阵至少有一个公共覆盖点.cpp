/*
    中位数贪心： 求 sum(abs(xi - p)) 的 最小值，p显然为xi的中位数 

    题意：给定n个矩形,x1,y1,x2,y2其中(x1,y1)为左下角, (x2,y2)为右上角  x,y <= 1e9 n <= 1e5
          求移动最少的步数使得所有矩阵至少有一个公共覆盖点, 每次操作可以将矩形上下左右移动
    思路： 横纵地位相同, 考虑x轴, 问题转换 => 给定n条线段[l,r] 左右移动线段使得所有线段至少有一个交点的最少步数
           假设交点的坐标为x 则 ans += (abs(ri - x) + abs(li - x) - abs(ri - li)) / 2 (i <= n) 画图可以得出结论
           要使得上面的和为小, x显然要为所有 l1,r1,l2,r2,...,ln,rn的中位数，y轴同样处理

           abs(ri - x) + abs(li - x) - abs(ri - li) => r - l 为定值
           => abs(ri - x) + abs(li - x) li ri独立 可以合并也可以分开求
*/
int n;
int x[N],y[N],c[N];

int calc(int x[]){
    for(int i=1;i<=2*n;i++) c[i] = x[i];
    sort(c+1, c+1+2*n);
    int res = 0, p = c[n];
    for(int i=1;i<=n;i++){
        int l = x[i], r = x[n+i];
        res += (abs(r - p) + abs(l - p) - abs(r - l)) / 2;
    }
    return res;
}

void solve(){
    cin>>n;
    for(int i=1;i<=n;i++) cin>>x[i]>>y[i]>>x[n+i]>>y[n+i];
    int ans = 0;
    ans += calc(x);
    ans += calc(y);
    cout << ans << "\n";
}