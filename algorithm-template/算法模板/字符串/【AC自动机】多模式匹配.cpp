/**
 * AC自动机 O(m + n) 多模式匹配算法  
 * m主串长度 n所有模式串长度之和 
 * 
 * https://www.luogu.com.cn/problem/P3808
 * 题意：给定 n 个模式串 si 和一个文本串 t，求有多少个不同的模式串在文本串里出现过。两个模式串不同当且仅当他们编号不同。
 */
#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10;
int n;

namespace AC {
int tr[N][26], tot;
int e[N], fail[N];

void insert(char *s) {
  int u = 0;
  for (int i = 1; s[i]; i++) {
    if (!tr[u][s[i] - 'a']) tr[u][s[i] - 'a'] = ++tot;  // 如果没有则插入新节点
    u = tr[u][s[i] - 'a'];                              // 搜索下一个节点
  }
  e[u]++;  // 尾为节点 u 的串的个数
}

queue<int> q;

void build() {
  for (int i = 0; i < 26; i++)
    if (tr[0][i]) q.push(tr[0][i]);
  while (q.size()) {
    int u = q.front();
    q.pop();
    for (int i = 0; i < 26; i++) {
      if (tr[u][i]) {
        fail[tr[u][i]] =
            tr[fail[u]][i];  // fail数组：同一字符可以匹配的其他位置
        q.push(tr[u][i]);
      } else
        tr[u][i] = tr[fail[u]][i];
    }
  }
}

int query(char *t) {
  int u = 0, res = 0;
  for (int i = 1; t[i]; i++) {
    u = tr[u][t[i] - 'a'];  // 转移
    for (int j = u; j && e[j] != -1; j = fail[j]) {
      res += e[j], e[j] = -1;
    }
  }
  return res;
}
}  // namespace AC

char s[N];

int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%s", s + 1), AC::insert(s);
  scanf("%s", s + 1);
  AC::build();
  printf("%d", AC::query(s));
  return 0;
}