/**
 * 基本形式
 * 给出ai,bi wi 最大化/最小化 sum(ai*wi) / sum(bi*wi)
 * wi取值为0or1 不选或者选
 * 通过二分转化公式 以最大值为例
 * 二分枚举最大值
 * sum(ai*wi) / sum(bi*wi) > mid
 * 令 f = sum(wi*(ai-mid*bi)) > 0
 * if(f >= 0) l = mid //最大化答案
 * else r = mid
 */
const int N = 1e5 + 10;
int n;
double a[N],b[N];

bool check(double x){
    double s = 0;
    for(int i=1;i<=n;i++)   
        if(a[i] - x * b[i] > 0)
            s += a[i] - x * b[i];
    return s > 0;
}

// 二分
double L = 0, R = 1e9;
while (R - L > eps) {
    double mid = (L + R) / 2;
    if (check(mid))  // mid 可行，答案比 mid 大
        L = mid;
    else  // mid 不可行，答案比 mid 小
        R = mid;
}