/**
 * 单调栈 例题
 * 有n个高度为h[i]的柱子,求n根柱子构成的最大矩阵
 */
const int N = 1e5 + 10;
int n;
int h[N];
// l[i]左边第一个严格小于h[i]的下标 
// r[i]右边第一个严格小于h[i]的下标
int l[N],r[N],stk[N],tt; 

void solve(){
    for(int i=1;i<=n;i++) cin>>h[i];
    tt = 0; for(int i=1;i<=n;i++){
        while(tt > 0 && h[stk[tt]] >= h[i]) tt -= 1;
        l[i] = (tt > 0 ? stk[tt] : 0);
        stk[++tt] = i;
    }
    tt = 0; for(int i=n;i>=1;i--){
        while(tt > 0 && h[stk[tt]] >= h[i]) tt -= 1;
        r[i] = (tt > 0 ? stk[tt] : n+1);
        stk[++tt] = i;
    }
    // 枚举以第i根柱子为基准
    int ans = 0;
    for(int i=1;i<=n;i++){
        int len = i - l[i] + r[i] - i - 1;
        ans = max(ans, h[i] * len);
    }
    cout << ans << "\n";
}
