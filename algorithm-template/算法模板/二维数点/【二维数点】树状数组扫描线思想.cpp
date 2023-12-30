// 二维数点/偏序
// 二维数点的核心：枚举一维 数据结构维护一位！
// 给定二维平面内若干点 多次询问指定矩形区域内包含的点数(包含边界)
// <=>
// 给一个长为 n 的序列，多次询问区间 [l,r]中 值在[x,y]内的元素个数

// 模板题  园丁的烦恼
// https://www.luogu.com.cn/problem/P2163

#include <bits/stdc++.h>
using namespace std;
const int N = 1e7 + 10, M = 5e5 + 10;
int n,m;

struct Q{
    // 询问s[x][y]对ans[id]影响权值为w
    int x,y,w,id;
    bool operator < (const Q& o) const {
        return x != o.x ? x < o.x : y < o.y;
    }
};

int ans[M];
vector<pair<int,int>> points; 
vector<Q> q;

int tr[N];
int lowbit(int x){return x&-x;}
void add(int x,int c){for(int i=x;i<=n;i+=lowbit(i)) tr[i] += c;}
int sum(int x){int res = 0;for(int i=x;i;i-=lowbit(i)) res += tr[i];return res;}

int main(){
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++){
        int x,y; scanf("%d%d",&x,&y); ++x; ++y;
        points.push_back({x,y});
    }
    //1.将所有点按横坐标排序
    sort(points.begin(), points.end());
    //2.将所有矩形询问拆成四个区,即四次询问,所有询问按x轴排序 二维前缀和拆分
    for(int i=0;i<m;i++){
        int x1,y1,x2,y2; scanf("%d%d%d%d",&x1,&y1,&x2,&y2); 
        ++x1; ++y1; ++x2; ++y2;
        q.push_back({x2,y2,1,i});
        q.push_back({x2,y1-1,-1,i});
        q.push_back({x1-1,y2,-1,i});
        q.push_back({x1-1,y1-1,1,i});
    }
    sort(q.begin(), q.end());
    int cur = 0;
    //3.遍历询问,设当前横坐标为 x ,确保<=x的所有点的纵坐标已加入树状数组,在树状数组中查询答案,贡献加至原询问处
    for(auto [x,y,w,id] : q){
        while(cur < n && points[cur].first <= x){
            add(points[cur].second, 1); cur++; 
        }
        ans[id] += w * sum(y);
    }
    //4.输出每个原询问的答案
    for(int i=0;i<m;i++) printf("%d\n", ans[i]);
    return 0;
}