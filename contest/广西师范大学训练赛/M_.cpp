#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
const int mod = 20000311;
const int INF = 0x3f3f3f3f;
const int N = 5e5 + 10;
 
struct StringHash 
{
    ll h[N], w[N], base, mod; 
    void Init(ll b, ll m)
    {
        h[0] = 0, w[0] = 1, base = b, mod = m;
    }
    void Add(char* s)
    {
        int len = strlen(s + 1);
        for (int i = 1; i <= len; i++)
            h[i] = (h[i - 1] * base + s[i]) % mod, w[i] = w[i - 1] * base % mod;
    }
    ll Get(int l, int r)
    {
        return (h[r] - h[l - 1] * w[r - l + 1] % mod + mod) % mod;
    }
}ha1, ha2;
char t[N];
char s[N];
int n;
bool check()
{
    for (int i = 1; i <= n; i++)
    {
        if (i <= n - i)
        {
            if (ha1.Get(1, i) == ha1.Get(n - i + 1, n))
            {
                if (ha1.Get(i + 1, n - i) == ha2.Get(i + 1, n - i))
                    return 1;
            }
        }
        else
        {
            int len = n - i;
            if (ha1.Get(n - 2 * len + 1, n - len) == ha1.Get(n - len + 1, n))
            {
                if (ha1.Get(1, n - 2 * len) == ha2.Get(2 * len + 1, n))
                    return 1;
            }
        }
    }
    return 0;
}
int main()
{
#ifdef LOCAL
    freopen("E:/input.txt", "r", stdin);
#endif
    ha1.Init(233, 1e9 + 9);
    ha2.Init(233, 1e9 + 9);
    int T;
    cin >> T;
    while (T--)
    {
        scanf("%s", t + 1);
        int len = strlen(t + 1);
        n = 0;
        for (int i = 1; i <= len; i++)
        {
            if (t[i] != t[len - i + 1])
            {
                for (int j = i; j <= len - i + 1; j++)
                    s[++n] = t[j];
                break;
            }
        }
        if (n == 0)
        {
            puts("Yes");
            continue;
        }
        ha1.Add(s);
        reverse(s + 1, s + n + 1);
        ha2.Add(s);
        int ans = check();
        if (!ans)
        {
            ha1.Add(s);
            reverse(s + 1, s + n + 1);
            ha2.Add(s);
            ans = check();
        }
        puts(ans ? "Yes" : "No");
    }
    return 0;
}

