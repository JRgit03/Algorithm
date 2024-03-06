/**
 * 带修莫队 时间复杂度O(m * n^(2/3)) n = m 是 O(n^(5/3)) n = m = 150000 => 4e8
 * 题目大意：给你一个序列，M 个操作，有两种操作：
 *      1.修改序列上某一位的数字 [R,P,C] replace 第P个数字为C
 *      2.询问区间 [l,r] 中数字的种类数（多个相同的数字只算一个） [Q,L,R]
*/
#include <bits/stdc++.h>
using namespace std;

int qsize;
struct query {
  int id, t, l, r; // 编号,修改次数,查询区间左端点,右端点

  inline bool operator<(query b) {
    if (l / qsize != b.l / qsize) {
      return l / qsize > b.l / qsize;
    } else if (r / qsize != b.r / qsize) {
      return r / qsize > b.r / qsize;
    } else {
      return t > b.t;
    }
  }
} q[150009];

struct operation {
  int p, x;
} r[150009]; // r[i] = {p,x} 第i次修改 将下标为p的值修改为x

char op;
// qcnt 询问次数 rcnt 修改次数 cur 数值种类数 mp 统计出现次数
int n, m, x, y, cur, qcnt, rcnt, mp[1500009], a[150009], ans[150009];

inline void add(int x) {
    if (!mp[x]) cur += 1;
    mp[x] += 1;
}

inline void del(int x) {
    mp[x] -= 1;
    if (!mp[x]) cur -= 1;
}

inline void process() {
    sort(q + 1, q + qcnt + 1);
    int L = 1, R = 0, last = 0; // [l,r,last] last表示当前询问前面已经有了last次修改
    for (int i = 1; i <= qcnt; i++) {
        while (R < q[i].r) add(a[++R]);
        while (R > q[i].r) del(a[R--]);
        while (L > q[i].l) add(a[--L]);
        while (L < q[i].l) del(a[L++]);
        while (last < q[i].t) { // 修改
            last += 1;
            if (r[last].p >= L && r[last].p <= R) { // 当前修改的pos在本次[L,R]查询中
                add(r[last].x); // 添加新值
                del(a[r[last].p]); // 删除旧值
            }
            swap(a[r[last].p], r[last].x); // 序列的值和操作的值交换 妙!
        }
        while (last > q[i].t) { // 撤销
            if (r[last].p >= L && r[last].p <= R) {
                add(r[last].x);
                del(a[r[last].p]);
            }
            swap(a[r[last].p], r[last].x); 
            last -= 1;
        }
        ans[q[i].id] = cur;
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n >> m;
    qsize = pow(n, 2.0 / 3.0);
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= m; i++) {
        cin >> op >> x >> y;
        if (op == 'Q') {
            q[++qcnt] = {qcnt, rcnt, x, y};
        } else if (op == 'R') {
            r[++rcnt] = {x, y};
        }
    }
    process();
    for (int i = 1; i <= qcnt; i++) cout << ans[i] << "\n";
    return 0;
} // 《算法竞赛》P222